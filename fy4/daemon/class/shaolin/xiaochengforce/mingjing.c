#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
	    if(me->query("class")!="shaolin") 
			return notify_fail("ֻ������ɮ�˲���ʹ�á�������\n");

		limit = "self";
		amount = me->query_skill("xiaochengforce",1);
		cost = 50;
		msg_self = WHT"$N�������Ƶ���һ΢�������������ɾ�һ��΢����������΢���಻������һ������˼ɲ��\n" NOR;
		msg_target = "";
		type = "kee";
			
		general_heal( me, target, "self", amount, cost, msg_self, msg_target, type);				
		return 1;
}
