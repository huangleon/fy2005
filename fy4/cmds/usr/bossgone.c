// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	if(me->query_temp("proprop") && me->query_temp("block_msg/all")>=1)
	{
		me->add_temp("proprop",-1);
		me->add_temp("block_msg/all",-1);
		write(CLR);
		write("��Ļ����ָ�����״̬�������������\n");
	} else
		write("��û��ʹ�ù�BOSSָ�\n");
		
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: bossgone  

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ָ���ʽ: bossgone  [0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������(���)���ϰ��ߺ�ָ�����������Ϸ��

�й�ָ�boss

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
