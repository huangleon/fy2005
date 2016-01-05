#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{

	if (!arg) 
		return notify_fail("��������Ҫ��������μ�����𡡣��롣\n");
		
	if (!me->query("afk_msg"))
		me->set("afk_msg",WHT"�Բ������Ժ���ϵ��\n"NOR);
	
	if(arg == "on") {
		me->set("env/afk",1);
		tell_object(me,WHT"�������趨Ϊ���״̬��\n"NOR);
		tell_object(me,WHT"����Զ�����ϢΪ��"+me->query("afk_msg")+"��\n"NOR);
		return 1;
	}
	
	if (arg=="off") {
		me->set("env/afk",0);
		tell_object(me,WHT"��ȡ�������״̬��\n"NOR);
        	return 1;
        }
	
	me->set("afk_msg",arg);
	tell_object(me,WHT"�趨�������Զ�����ϢΪ��"+me->query("afk_msg")+"��\n"NOR);
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ������ <ѶϢ>[0m
[0;1;37m����������������������������������������������������������������[0m

���ָ�������趨�ڷ���״���µ��Զ��𸴣�ʹ�÷���Ϊ��

���롡�������Զ��𸴡�

���롡���桡�ر��Զ��𸴡�

���롡���Զ�����Ϣ�����������Լ����Զ�����Ϣ��

������

�����趨���롡�������ģ����졡����������ˣ���á�
�����Զ������ģ�����ȥ�Է��ˣ���������ġ���
[0;1;37m����������������������������������������������������������������[0m
HELP
	);
	return 1;
}
