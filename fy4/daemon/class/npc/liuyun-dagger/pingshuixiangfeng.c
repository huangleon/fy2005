// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("yuping-dagger",1);
	if ( extra < 70) return notify_fail("��ģ���ƽ�̱��Уݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ƽˮ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);
	me->add_temp("apply/attack", extra/10);
	msg = HIW "$N���һ����----Ƽ----ˮ----��----��----��\n" + HIR "Ƽ---���е�" + weapon->name() + HIR "�����߰����$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIR "ˮ---ֻ��"+ weapon->name()+ HIR "�������ԣ�����$n����磡" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
     	msg = HIR "��---$N���һ����"+ weapon->name()+ HIR "�����������$n���ؿڣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
   	msg = HIR "��---$Nͼ��ذ�֣��Ӹ����£�����"+ weapon->name()+ HIR "��$n�Ĵ�����ȥ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -extra);
	me->add_temp("apply/attack", -extra/10);
	me->start_busy(4);
	return 1;
}
