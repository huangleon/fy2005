// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int extra, int skill);
int perform(object me, object target)
{
	string msg;
	int extra, skill,resist;
	object weapon;
	
	if(userp(me)&& !wizardp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
			
	if(me->query("class")!="swordsman")
		return notify_fail("��ֻ�н���ĵ��Ӳ����ʸ��ã�\n");
	
	if(me->query_skill("softsword",1)<50)
		return notify_fail("�����ϸ�����ὣ������Ϊ������\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ĺ��ɺ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

			
	weapon = me->query_temp("weapon");
	
	extra = me->query_skill("sword");
	skill = me->query_skill("softsword",1);
	
	target->delete_temp("last_damage_from");
	
	me->add_temp("apply/attack", skill);	
	me->add_temp("apply/damage", extra);
	msg = HIC "$Nһ���ӳ�����Ϧ�����������գ���ʺ磬�������ƣ��綯�־���������ʵ��
�����������ң�����ǰ�������ᣬ��������������ʵ�� \n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -extra);
	
	if(target->query_temp("last_damage_from") && (!userp(me) || skill>170)) {
		msg=HIW"������ɺ磬ɭ���Ľ��������������衣\n"NOR;	
       		me->add_temp("apply/attack", skill*3);    
       		me->add_temp("apply/damage", extra*2);		
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack", -skill*3);
       		me->add_temp("apply/damage", -extra*2);
       		if (me->query_busy()<3) me->start_busy(3);
		}
	else {
		if (me->query_busy()<2) me->start_busy(2);
		}
	return 1;
}
