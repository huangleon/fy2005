// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    string target, mud;
    object obj;
    string refuse_name,filename;

    if( !arg || arg=="" )
	return notify_fail("��Ҫ�ش�ʲ�᣿\n");
    if(me->query("chblk_on"))
	return notify_fail("���Ƶ�������ˣ�\n");
    if( !stringp(target = me->query_temp("reply")) )
	return notify_fail("�ղ�û���˺���˵������\n");

    if( sscanf(target, "%s@%s", target, mud)==2 ) {
	GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
	write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
	return 1;
    }

    obj = find_player(target);
    if( !obj )
	return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
    if(obj->query_temp("is_unconcious")) return notify_fail("��/�������޷�������˵�Ļ���\n");
    if(obj->query_temp("block_msg/all")) return notify_fail("��/�������޷�������˵�Ļ���\n");

    refuse_name = (string) obj->query("env/no_tell");
    if( !wizardp(me) && (refuse_name == "all" || refuse_name == (string) me->query("id")))
	return notify_fail("�����ѹر��ˣԣţ̣�Ƶ����\n");
    write(YEL "��ش�" + obj->name(1) + "��" + arg + "\n" NOR);
    tell_object(obj, sprintf(YEL"%s�ش��㣺%s\n"NOR,
	me->name(1), arg ));

	// MONITORING
	if (obj->query("MONITORING")>=2){
		filename = getuid(obj);
		log_file("backup/" + filename, sprintf(
				"%s %s at %s �ش� %s --- %s\n",
				me->query("id"), me->query("name"),
				ctime(time()),
				filename, 
				arg) );
	}
	
	if (me->query("MONITORING")>=2){
		filename = getuid(me);
		log_file("backup/" + filename, sprintf(
				"%s %s at %s �ش� %s --- %s\n",
				me->query("id"), me->query("name"),
				ctime(time()),
				obj->query("id"), 
				arg) );
	}
	// END MONITORING

    obj->set_temp("reply", me->query("id"));
    return 1;
}

int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	reply <ѶϢ>[0m
[0;1;37m����������������������������������������������������������������[0m   
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
