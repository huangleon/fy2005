// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	
	if (me->query_temp("proprop") || me->query_temp("block_msg/all"))
		return 1;
		
	write(CLR);	
	if(arg)
	{
		msg = read_file("/obj/nonsense.txt");
		write(msg);
	}
	me->add_temp("block_msg/all",1);
	me->add_temp("proprop",1);
	return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	boss <arg>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������(���)���ϰ����ǰһ����ʱ����Ļ��
���е��������������<arg>������Ļ������ƻ���
�����Ļ����ʾ��һЩ���¡�
���ͬʱ���㽫�ܲ����κ����Է��Ƶ�ѶϢ��ֱ����
����bossgoneָ�

�й�ָ�bossgone

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
