// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
int imbue_event(object me);
inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
��ѩ�Ѿ����ˣ���ɽ���Ѿ���ѩ�ں��峺��Ȫˮ��������������ɽ֮�۵�
���������һƬ�Թ������ʹ��ڵĻ�ѩ����Ȼ�����������⡣����һƬ����
ɫ��������������ﶼ�����б仯����������˵��û�б仯��ֻ����������
�仯�����������������ȫû��������
LONG
        );
	set("exits",([
  		"southdown" : __DIR__"houmen",
  		"northup" : __DIR__"feilai",
  		"enter" : __DIR__"icecave",
	]) );

	set("outdoors", "xiangsi");
	set("no_fight",1);

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",30);
	setup();
}

void do_ggyy(object me,object li,object xue,int count)
{
	string msg;
	mapping buff;
	string *event_msg = ({
WHT"��ɫѩ���䣬�·��в㵭��������Ʈ���������·���һ����������Ӱ��",
"",
CYN"������������˶��촽��ȴһ����Ҳû��˵��",
CYN"Ѧ���غ���˫�ۣ���������һ�ж�ʤ����",
CYN"����ͷ��������������������Ц�������ҽ��棬����ֻ��һ�С�",
CYN"�á�Ѧ���ش���������һ������ɫ��С��������Ө����������С�\n"HIW"���ϵ����µĹ�â��һ˲���������Ǳ���ɫ��С��ɢ��ѩ�׵ĻԻ���ӳ�ú�������������硣",
CYN"����������˫�ۣ�ֱ������롣",
CYN"���������˿�����������꣬�����ͳ���������ᱡ�ķɵ���",
"",
WHT"һ��������ɽ���������ϵ�ѩ���𵭵����ʵİ���",
"",
CYN"��ֻ������ǰ����һ������������Ծ����˫˫���֡���",
CYN"�����鷢��С��ɵ���������ȴ�Ƕ��������Ĺ��ɶ�ȥ������������зɳ�\n��ֻ�Ǽ��ξ�Ө��ˮ�飻��֪��ʱ�Ǿ����Ĺ���ֹ��������¡�",
HIC"������䡣\n\nѦ��������΢�ݣ��쳤��ϸ�Ĳ�������ӭ���Ǳ���ƫ��ķɵ���\n\n�������⡣\n\n��Ӱ����Ծ�����㻹�������巢����ʲô�����Ѿ�������",
HIR"����Ѧ���ر�ײ��һ�ԣ����ĺ��ˣ�������ǰ��һ���ʺ��Ѫ��������ؽ�\n��ѩ���ϣ��ڲҵ�����ɫ���Ե÷������ޡ���Ѫ�ľ���������������ھ�ǰ��\n�ɵ������׷�������ָ֮�䡣\n\nС��ɵ��������鷢��ֻ���ǵ�һ�Σ�Ҳ�����һ�Σ������鷢�ķɵ��������˵����ϡ�\n\n���ĺ����������죬����ʹ��ȴ��Ȼ���ŵķ�������ײ�������ϵ�����Ѧ����\nü�����磬���ｻ֯�Ű��⡢�ɾ塢������ʹ�࣬���������Ĵ���ͷ���ҡ������ˡ�\n\n����ʹ��Ť�������Ͻ���������һĨ΢Ц�����ӻ���һ�Σ��������ڵ��ϡ�\n��ʼ���ճ�ȭ�����ֽ����ɿ���¶���ѱ���ˮʪ����һ��ҩ�ۡ�",
HIW"�����Ӱ��΢΢����������Ż������µ�һ�����̣���ȥ���١�",
WHT"��������վ�ŵĵط���һ�����ɫ��ˮ�黬�£�",
HIW"��֪��ʱ����������Ʈ�����������ѩ�������ϵ�Ѫ����������壬�ż���ȥ��",
});
	if (!me )
		return;
	if (!li && count < 14)
	{
		if (xue)
			destruct(xue);
		return;
	}
	if (!xue && count < 16)
	{
		if (li)
			destruct(li);
		return;
	}
	if (count < 14 && environment(me) != environment(li))
	{
		if (li)
			destruct(li);
		if (xue)
			destruct(xue);
		return;
	}
	if (count < 16 && environment(me) != environment(xue))
	{
		if (li)
			destruct(li);
		if (xue)
			destruct(xue);
		return;
	}
	msg = event_msg[count];


	message_vision("\n"+CYN+msg+NOR+"\n",li,me);

	if (count == 14)
	{
		li->die();
		li=present("corpse",this_object());
	}
	if (count == 16)
	{
		destruct(xue);
		imbue_event(me);
	}

	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1,me,li,xue,count+1);
	else
	{
		if (li)
			destruct(li);
		if (xue)
			destruct(xue);
		set("start",0);
		REWARD_D->riddle_done(me,"������Թ",100,1);

//		write(me->query_busy()+"i");
		return;
	}
	return;
}


int start(object who)
{
	object npc1,npc2;
	set("start",1);
	npc1=new(__DIR__"npc/lihuai");
	npc2=new(__DIR__"npc/xue");
	npc1->move(this_object());
	npc2->move(this_object());
	who->start_busy(20);
	call_out("do_ggyy",1,who,npc1,npc2,0);
}

int init()
{
	object who = this_player();
	if (!NATURE_D->is_day_time())
		if (REWARD_D->riddle_check(who,"������Թ") == 11  )
			if (!query("start"))
				start(who);
}


int imbue_event(object me)
{
	object weapon, obj, *inv;
	string prop;
	int i;
	int j;
	mapping data;

	if(!interactive(me) || environment(me) != this_object()){
		return 0;
	}

	j = me->query("����B/��˼_����");

	if(me->query("imbue/moon_xue"))
	{
			message_vision(WHT"������ѩ���ϣ�����һ��СС���ʺ�÷����\n"NOR,me);
	} 
	else 
	{
		message_vision(WHT"������$N�����ģ�����һ��СС���ʺ�÷����\n"NOR, me);  
		data = ([
			"name":		"������Թ",
			"target":	me,
			"att_2":	"str",
			"att_2c":	1,
			"mark":		3,
		]);

		REWARD_D->imbue_att(data);	
		me->set("imbue/moon_xue", 1);
		me->save();
		log_file("riddle/IMBUE_LOG",
			sprintf("%s(%s) �⿪ ������Թ���õ���� event %d. %s \n",
				me->name(1), geteuid(me), j, ctime(time()) ));
		return 1;
	} 
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
