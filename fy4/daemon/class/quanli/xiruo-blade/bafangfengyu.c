// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("xiruo-blade",1);
	if ( extra < 50) return notify_fail("��ģ�Ϣ�������ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۰˷������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);

	msg =  HIR "$Nʹ��Ϣ�������е����������һ��----�۰˷�����ݣ����е�"+ weapon->name()+ HIR "�����ؿ���$n��˫�ƣ�" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg =  HIB "$N���һ����"+ weapon->name()+ HIB"����$n���Ҽ磡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIC "$N��Хһ�����۹��������֣�ʹ����������߾���--�ֵ�����$n����ǰ��ȥ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -extra);
	me->start_busy(5);
	return 1;
}
