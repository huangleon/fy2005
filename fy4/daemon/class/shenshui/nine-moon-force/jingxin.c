#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		if (me->query_skill("qingpingforce",1) < 100)
			return notify_fail("�����ķ�����Ҫ100������ƽ�ķ���\n");
	
		limit = "self";
		amount = me->query_skill("qingpingforce",1);
		cost = 50;
		msg_self = WHT "$N"NOR+WHT"����ƽ����������ƽ�ķ��Ŀھ�̤̤ʵʵ�ش���һ��ȭ����\n" NOR;
		msg_target = "";
		type = "kee";
			
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}


















