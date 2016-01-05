// tell.c

#include <ansi.h>
#include <net/dns.h>
#define NEW_PERIOD 32400
inherit F_CLEAN_UP;

int help(object me);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
    string target, msg, mud;
    object obj;
    string name, refuse_name, filename;

    if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
    if(me->query("chblk_on"))
		return notify_fail("���Ƶ�������ˣ�\n");
    if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("��ֻ����ʹ�ã�say����\n");
    if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
    }
    obj = find_player(target);
    if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
    if (obj==me) return notify_fail("��������б�Ҫô��\n");
    if(obj->query_temp("is_unconcious")) return notify_fail("��/�������޷�������˵�Ļ���\n");
    if(obj->query_temp("block_msg/all")) return notify_fail("��/�������޷�������˵�Ļ���\n");

    name = (string) me->query("id");
    refuse_name = (string) obj->query("env/no_tell");
    if( !wizardp(me) && (refuse_name == "all" || refuse_name == name))
		return notify_fail("�����ѹر��ˣԣţ̣�Ƶ����\n");
    write(YEL "�����" + obj->name(1) + "��" + msg + "\n" NOR);
    
    tell_object(obj, sprintf( YEL "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	// MONITORING
	if (obj->query("MONITORING")>=2){
		filename = getuid(obj);
		log_file("backup/" + filename, sprintf(
				"%s %s at %s ���� %s --- %s\n",
				me->query("id"), me->query("name"),
				ctime(time()),
				filename, 
				msg) );
	}
	
	if (me->query("MONITORING")>=2){
		filename = getuid(me);
		log_file("backup/" + filename, sprintf(
				"%s %s at %s ���� %s --- %s\n",
				me->query("id"), me->query("name"),
				ctime(time()),
				obj->query("id"), 
				msg) );
	}
	// END MONITORING
	
    obj->set_temp("reply", me->query("id"));

    if (obj->query("env/afk")) {
		if(!obj->query("afk_msg")) obj->set("afk_msg","�Բ������Ժ���ϵ��\n");
		tell_object(me, sprintf(YEL"%s���ڲ��ڼ�����ߣ��Զ��ش��㣺%s\n"NOR,
	    	obj->name(1), obj->query("afk_msg")));		
		tell_object(obj, sprintf(YEL"���Զ��ش�%s��%s\n"NOR,
	    	me->name(1), obj->query("afk_msg")));		
    }

    return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
    object ob;

    if( ob = find_player(to) ) {
	if( cname )
	    tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR,
		cname, capitalize(from), mud, msg ));
	else
	    tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
		capitalize(from), mud, msg ));
	ob->set_temp("reply", from + "@" + mud);
	return 1;
    } else
	return 0;
}

int help(object me)
{
    write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	tell <ĳ��> <ѶϢ>[0m
[0;1;37m����������������������������������������������������������������[0m   

����������ָ��������ط���ʹ����˵����

�������ָ�reply

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
