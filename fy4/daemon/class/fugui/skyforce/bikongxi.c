#include <ansi.h>
#include "/daemon/class/GENERIC/FORCE/generic_heal.c"

int exert(object me, object target, int amount)
{
		string msg_self, msg_target,limit, type;
		int cost;
		
		limit = "self";
		amount = me->query_skill("skyforce",1);
		cost = 50;
		msg_self = WHT"$N����������ת��..
Ƭ��֮��$Nͷ��ð��˿˿���������һ��������ͷ����̿�һϴ����ɫ������������ˡ���\n" NOR;
		msg_target = WHT"$N����������ת��˫�ƽ���$n���ģ���������������$n����....
Ƭ��֮��$Nͷ��ð��˿˿������$n���һ��������ͷ����̿�һϴ����ɫ������������ˡ�\n"NOR;
		type = "kee";
		
		general_heal( me, target, "party", amount, cost, msg_self, msg_target, type);				
		return 1;
}