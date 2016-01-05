//BBB 09/25/1999
//����Ҳ���©���κ���Ҫ���ţ�Ҳ��Ҫ��;����ȥ����ʦ����档
// Modify by snowman@SJ for new_list when login.
// Modified By Numa@SJ 2000.3.31 For write all to player
// Modified By bbb@SJ 2000.11.03 For Mysql
// Modified by snowman@SJ 19/12/2000 for faster speed.

// Modified for fy game... credits go to above authors.

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>

#define NEWS_DIR       "/data/"
#define NEWS_FILENAME  "news"

#define NEWS_TITLE  "\n================================= "HIC"���ƹ���ϵͳ"NOR" =====================================\n"
#define NEWS_END  "====================================================================================\n"

#define NEWS_P HIY"���ƹ���ϵͳ��"NOR

inherit F_SAVE;

static object ob = 0;
static int status=0;
static string msg,subject;

mapping *notes;

string query_save_file()
{
	return NEWS_DIR + NEWS_FILENAME ;
}

void tell_me(string msg)
{
	if (objectp(ob)) tell_object(ob, msg);
}

void done_post(object me,mapping note, string text)
{
	int i;
	note["msg"] = text;
	i = sizeof(notes);
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });
	note["time"] = time();
	tell_object(me, NEWS_P + HIM "���ŷ�����ϡ�\n"NOR);
	save();
	return;
}

void list_news(object me, int login)
{
	int i = 0, ulogin, j = 0;
	string str;

	if (sizeof(notes) < 1)
		write("������Ϊ�ա�\n");
	else {
		ulogin = me->query("last_news");
		str = NEWS_END;
		foreach (mapping item in notes) {
			i++;
			if (ulogin < item["time"]) {
				if (j++ < 15)
					str = sprintf("%3d) %-=40s %18s (%s)\n%s",
						i, item["title"],
						wizardp(me)?item["poster"]+"("+capitalize(item["author"])+")":"",
						ctime(item["time"])[0..9], str
					);
			}
		}
		if (!j)
			write("Ŀǰû���µĹ��档\n");
		else {
			if (login && j > 5)
				;
			else
				write(NEWS_TITLE + str);
			write("\n");
			write(YEL"��ǰ���� "WHT+ i +YEL" �����桢"HIR+ j +NOR+YEL" ��δ����\n");
			write("���� fynews �Ķ����⣬���� fynews new|next|��� �Ķ��������ݡ�
��ϸָ������� help fynews \n\n"NOR);
		}
	}
}

void list_allnews(object me)
{
	int i;
	string str;

	i = sizeof(notes);
	if ( i < 1) {
		write(NEWS_P +"û���κι��档\n");
		return;
	}
	str = NEWS_TITLE;
	while( i-- )
		str += sprintf("%3d) %-=40s %18s (%s) \n",
			i+1, notes[i]["title"], wizardp(me)?notes[i]["poster"]+"("+capitalize(notes[i]["author"])+")":"",
			ctime(notes[i]["time"])[0..9] );
	str += NEWS_END;
	me->start_more("",str,0);
}

void create()
{
	seteuid(getuid());
	restore();
	call_out("create", 900);
}

int main(object me, string arg)
{
	mapping note;
	string s,arg1;
	int num = -1;

	if (!arg) {
		list_news(me, 0);
		return 1;
	}

	if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_allnews(me);
			return 1;
		}
		if ( s == "post" ){
			if( wiz_level(me)<3 )
				return notify_fail(NEWS_P +"ֻ����ʦ�ſ��Է�����Ϣ�� \n");
			else 	return notify_fail("ʹ�÷����� fynews post <����> \n");
		}
		if ( s == "delete" ){
			if( wiz_level(me)<3 )
				return notify_fail(NEWS_P +"ֻ����ʦ�ſ���ɾ����Ϣ�� \n");
			else	return notify_fail("ʹ�÷����� fynews delete <���> \n");
		}
		
		if (s == "announce") {
			if (wiz_level(me)<3)
				return notify_fail(NEWS_P +"ֻ����ʦ�ſ��Թ�����Ϸ��\n");
			CHANNEL_D->do_sys_channel("info","������Ϸ�����µĹ��棬�뼰ʱ��fynewsָ���ѯ��лл��");
			return 1;
		}
	}

	if (sscanf(arg, "post %s", arg1) == 1) {
		if ( wiz_level(me)<3 )
			return notify_fail(NEWS_P +"ֻ����ʦ�ſ��Է�����Ϣ�� \n");
		if ( strlen(arg1)< 8 || strlen(arg1)>40 )
			return notify_fail(NEWS_P +"�������Ҫ��˵�����⣬��������������4-20֮�䡣 \n");
		else note = allocate_mapping(5);
		note["title"] = arg1;
		note["author"] = getuid(me);
		note["poster"] = me->query("name");
		me->edit( (: done_post, me, note :) );
		return 1;
	}

	if (sscanf(arg, "delete %d", num)== 1) {
		if ( wiz_level(me)<3 )
			return notify_fail(NEWS_P +"ֻ����ʦ�ſ���ɾ����Ϣ�� \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail(NEWS_P +"û�������ŵĹ��档\n");
		else num--;
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write(NEWS_P +"ɾ���� " + (num+1) + " �Ź���....Ok��\n");
		return 1;
	}

	if (arg == "new" || arg == "next") {
		int ulogin = me->query("last_news");

		num = sizeof(notes);
		while (num--)
			if (ulogin >= notes[num]["time"])
				break;
		num+=2;
	}

	if (num+1 || sscanf(arg, "%d", num) == 1) {
		int size = sizeof(notes);

		if (!size)
			return notify_fail(NEWS_P +"û���κι��档\n");
		if (num < 1 || num > size)
			return notify_fail(NEWS_P +"û�������ŵĹ��档\n");
		num--;
		me->start_more("",sprintf("%d) %-=43s %8s(%s)(%s)\n"+NEWS_END,
			num + 1, notes[num]["title"],
			wizardp(me)?notes[num]["poster"]:"",
			wizardp(me)?notes[num]["author"]:"News",
			ctime(notes[num]["time"])[0..15]) + notes[num]["msg"],0
		);
		write(NEWS_END);
		if (me->query("last_news") < notes[num]["time"])
			me->set("last_news", notes[num]["time"]);
		return 1;
	}

	if ( arg == "write all" ) {
		if (!wizardp(me))
			return notify_fail("������ʦ���\n");
		if( !pointerp(notes) || !sizeof(notes) )
			return notify_fail(NEWS_P +"û���κι��档\n");
		msg = NEWS_TITLE;
		for (num=0;num<sizeof(notes);num++) {
			msg += sprintf(HIW"%d"NOR") %-=43s %8s(%s)(%s)\n"+NEWS_END,num + 1, notes[num]["title"],
				wizardp(me)?notes[num]["poster"]:"",wizardp(me)?notes[num]["author"]:"",
				ctime(notes[num]["time"])[0..15]) + notes[num]["msg"] + "\n\n";
		}
		me->start_more("",msg,0);
		return 1;
	}
	
	return notify_fail("��ʹ��help fynews���鿴���е��йز�����\n");
}

int help(object me)
{
	if (!wiz_level(me) )
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ[0m

fynews			�鿴���ʮ����δ���Ĺ��档
fynews all		�鿴ȫ�������б�
fynews new|next	�鿴���һ��δ���������ϸ���ݡ�
fynews <���>		�鿴�˱�Ź������ϸ���ݡ�

[0;1;37m����������������������������������������������������������������[0m   

HELP);

	else
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ[0m

fynews				�鿴���ʮ����δ���Ĺ����б�
fynews all			�鿴ȫ�������б�
fynews announce			���������µĹ��档
fynews new|next			�鿴���һ��δ���������ϸ���ݡ�
fynews <���>			�鿴�˱�Ź������ϸ���ݡ�
fynews post <����>		�������棬wizard ����������ʦר��
fynews delete <���>		ɾ�����棬wizard ����������ʦר��
fynews write all			�г�ȫ�� news ����ϸ����

[0;1;37m����������������������������������������������������������������[0m   

HELP);
	return 1;
}