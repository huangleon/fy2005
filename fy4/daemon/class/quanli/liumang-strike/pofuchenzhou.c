// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	extra = me->query_skill("unarmed");

	if ( extra < 300) return notify_fail("�����å��ȭ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���Ƹ����ۣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add("force_factor",extra/3);
	orforce = (int) me->query("force");
	me->add("force",extra/3*100);
	me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
	msg = HIY  "$Nʹ���������µģ���å��ȭ�ݣ�һ�У��Ƹ����ۣݣ��Դ�һ˿��ϧ֮ɫ��$n��ȫ��ҪѨ������\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "��һȭ------Ц���߽�һָ�ɣ�" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "�ڶ�ȭ------Ҷ��������ɽ����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "����ȭ------�����������ͷ������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "����ȭ------����̫����������������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "����ȭ------���¹����忴�أ���������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "����ȭ------ãã��ˮ�����죡����������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg = HIY  "����ȭ------Ц��Ҷ�俴���ƣ�������������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	msg = HIY  "���һȭ------���׻�������ˮ����������������" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	me->start_busy(5);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
	return 1;
}
