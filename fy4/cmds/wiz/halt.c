// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !me->is_fighting() )
		return notify_fail("�����ڲ�û����ս����\n");
	me->remove_all_killer();
	message_vision("$N����ʦ������ֹͣ���ⳡ�򶷡�\n", me);
	write("Ok.\n");
	return 1;
}

int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	halt[0m
[0;1;37m����������������������������������������������������������������[0m   

ֹͣ���������йص�ս����

[0;1;37m����������������������������������������������������������������[0m   
HELP
   );
   return 1;
}
