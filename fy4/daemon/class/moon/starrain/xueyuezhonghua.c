// annie 07.2003
// dancing_faery@hotmail.com
// NPC_ONLY * Final Strike

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,temp1;
	object weapon,*pros,shadow,newweapon;
	int attack_points, dodge_points,skill,count,i,j,k,level,num1;

	if (userp(me) && !wizardp(me))
		return notify_fail("����书��û�д����ؼ���\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ѩ���ջ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	skill = me->query_skill("starrain",1);

	if (skill < 200)
		return notify_fail("��ѩ���ջ�����Ҫ����200���ĺ���������\n");

	if (me->query_skill_mapped("force") != "snowforce")
       	return notify_fail("��ѩ���ջ���������ѩ�ľ�������\n");	// limit enforce

//	if (me->query("force") < 500)
//     	return notify_fail("��ѩ���ջ�����Ҫ��������500��������\n");	


	msg = HIW"$N"HIW"�����ϸָ�����ƻð�������ѩɫ��ө�⼫�����ۣ���$N"HIW"���н����˪��
������裬�����һ������Ŀѣ�ĻԻ͡�\n"NOR;
	message_vision(msg,me,target);

	msg = HIC"����һ�ֿջõ����У�����������������ϲ�ã���˲�仯Ϊǧ���Ѥ�õ��̻���
���˵����аγ������ϣ��������\n"NOR;
	message_vision(msg,me,target);

	me->add_temp("apply/attack",me->query_skill("throwing")*4);
	me->add_temp("apply/damage",me->query_skill("throwing")*3);

	target->add_temp("combat_no_report",1);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, " ");
	target->add_temp("combat_no_report",-1);

	me->add_temp("apply/attack",-me->query_skill("throwing")*4);
	me->add_temp("apply/damage",-me->query_skill("throwing")*3);

	if (target->query_temp("damaged_during_attack") )
	{
		message_vision(HIW"\n����������ػ����۽�$n"HIW"�����壬����$n"HIW"��ͥ����
������������һ�ư�������\n"NOR,me,target);
		COMBAT_D->report_status(target);
		target->perform_busy(3);
	}
	me->perform_busy(3);
	return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

