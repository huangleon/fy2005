// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int extra, int skill);
int perform(object me, object target)
{
	string msg;
	int extra, skill;
	object weapon;
	if(me->query("class")!="swordsman")
		return notify_fail("��ֻ�н���ĵ��Ӳ����ʸ��ã�\n");
	if(me->query_skill("softsword",1)<50)
		return notify_fail("�����ϸ�����ὣ������Ϊ������\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ĺ��ɺ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("muyu"))
		return notify_fail("���Ѿ���ʹ�ã�ĺ��ɺ���ˡ�\n");
			
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
		me->set_temp("muyu",1);
		call_out("begin_perform",1,me,target,extra,skill);
		}
	else {
		if (me->query_busy()<2) me->start_busy(2);
		}
	return 1;
}

int begin_perform(object me,object target,int extra, int skill)
{
	string msg;
	int resist;
        
    if (!me)	return 0;    
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) {
        	me->delete_temp("muyu",1);
            return 0;
    }
	msg=HIW"������ɺ磬ɭ���Ľ��������������衣\n"NOR;	
       	resist = target->query("resistance/kee");
       	target->set("resistance/kee",0);
       	me->add_temp("apply/attack", skill*3);    
       	me->add_temp("apply/damage", extra*2);		
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -skill*3);
       	me->add_temp("apply/damage", -extra*2);
	target->set("resistance/kee",resist);
	me->delete_temp("muyu");
	if (me->query_busy()<3) me->start_busy(3);
        return 1;
}
