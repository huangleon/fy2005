#include <ansi.h>
// shout.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
		return notify_fail("Ŀǰ�ݲ�������� shout��\n");
	if (!arg) return notify_fail("����Ҫ���ʲ��?\n");
	shout( HIW+me->name() + "������Х��" + arg + "\n"NOR);
	write(HIW"��������Х��" + arg + "\n"NOR);
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	shout <ѶϢ>[0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}
 
