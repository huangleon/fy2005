// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("zhao-sword",1);
	if ( extra < 70) return notify_fail("�����չ÷�������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��÷����ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	msg = CYN "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��\n��һ����÷��������" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = CYN  "�ڶ�����÷�����ȣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = CYN  "����������亮÷��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	msg = CYN  "���Ľ����꺮��ů��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = CYN  "���彣��÷�����ţ�"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->start_busy(2);
	return 1;
}
