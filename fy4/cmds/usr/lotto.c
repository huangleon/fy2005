#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	int num, num1;
	
	if (me->query_temp("timer/lotto100")+ 2 > time())
		return notify_fail("��ָ��ÿ������ʹ��һ�Ρ�\n");
		
	if (arg)	
		num = atoi(arg);
	
	if (!num || num >100)
		return notify_fail("��ֻ���������һ��0��100֮�����������ʽ��lotto <number>\n");
	
	num1 = random(num);
	
	message_vision(WHT"$N��0��"+ num + "֮��������"HIY + num1 + NOR+WHT"�㡣\n"NOR, me);
	me->set_temp("timer/lotto100", time());
	
	return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ :		lotto <number>[0;32m	
[0;1;37m����������������������������������������������������������������[0m   

���ָ�������������һ��������������֮�������

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
