#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
			
		limit = "self";
		amount = me->query_skill("skyforce",1);
		cost = 50;
		msg_target = HIY "$N�������أ����ƽ���$n��ͷ����������������$n����....
Ƭ��֮��$n��ɫһ�����ؿ�ů��������������յ��գ�����һ�����������������ˡ�\n"NOR;
		msg_self = HIY "$N�������أ�һ�ָ��������ת....
Ƭ��֮��$N��ɫһ�����ؿ�ů��������������յ��գ�����һ�����������������ˡ�\n" NOR;
		type = "sen";
		
		general_heal( me, target, "party", amount, cost, msg_self, msg_target, type);				
		return 1;
}