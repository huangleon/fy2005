#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("skyforce",1);
		cost = 50;
		msg_self = HIG "$N˫��ʮ֧��ָð��˿˿������˲������������ʮ������Ѩ....
Ƭ��֮��$N�о������棬���ⰻȻ�����һ���������������ö��ˡ�\n" NOR,
		msg_target = HIG "$N˫��ʮ֧��ָð��˿˿������˲������$nȫ����ʮ������Ѩ....
Ƭ��֮��$n�о������棬���ⰻȻ�����һ���������������ö��ˡ�\n" NOR,
		type = "gin";
		
		general_heal( me, target, "party", amount, cost, msg_self, msg_target, type);				
		return 1;
}

