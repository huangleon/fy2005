// mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int second_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	extra = me->query_skill("qiuzhi-sword",1);
	weapon=me->query_temp("weapon");
	if ( extra < 100) return notify_fail("����֦��ʽ���������죡\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۺ�÷���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	msg = HIG "$N����"+weapon->name()+HIG"����һ����Ŷ�����Ȼ�켣�����ڶ��������к�Ȼ��һ�������ĸо���\n"NOR ;
	msg+= WHT "һ����΢���ĵ��������ƺ��������лó����������ޡ�\n" ;
	message_vision(msg,me);
	
	/*
	if(random(me->query("combat_exp")+extra*extra*extra)>target->query("combat_exp")/3)
	{
		message_vision(YEL "$N�鲻�Խ�����������һ�����������ڵ����������С� \n"NOR,target);
		target->force_busy(3);
	}
	else
		message_vision(HIY "$Nһ���񣬲�Ϊ���ư�����ɵĻ���������\n"NOR,target);
	*/

	me->add_temp("apply/damage",extra*5);
	msg = HIW "���⻪��Ȼ���£���÷���ֲ���÷������ѩ���ֲ���ѩ��������$n��Χ��"NOR ;
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/damage",-extra*5);

	if (!target->query_temp("damaged_during_attack"))
	{
		message_vision(HIY "$N��ʵ���飬����÷ѩƮ��Ľ�Ӱ����������� \n"NOR,target);
	}	
	me->perform_busy(2);
	return 1;
}
