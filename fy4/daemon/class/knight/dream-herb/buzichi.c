// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *team, *team1;
   	int i, skill, enhance, num, amount, duration;
   	string msg;
   	mapping buff;

   	if(me->query("class")!="knight")
   		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ�á����Գ֡�\n");

	skill = me->query_skill("dream-herb",1);
	if (skill <200 || me->query_skill("herb",1)< 240)
		return notify_fail("�����Գ֡���Ҫ200���������廨����240������ҩ����\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����Գ֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	duration = me->query("timer/pfm/khl_buzichi")-time() + 20;
    if (duration>0)
       	return notify_fail("�㻹��Ҫ�ȴ�"+(duration)+"�������Ҳ����ٴ�ʹ�á����Գ֡�\n");
	
	amount = skill *2;		
	message_vision(BBLU + HIM "\n$N��Хһ����������Σ��û��������滨��ÿ�仨���д��׹�â��֮��ӣ����ɫ����״��\n"NOR, me);		
	
	me->set("timer/pfm/khl_buzichi", time());
	if (target->query("boss")|| target->query("big_boss"))
		duration = 10;
	else
		duration = 20;
		
	me->add_temp("apply/herb",amount);
	if (COMBAT_D->do_magic_attack(me, target, "herb", "kee", 0)) {	
	    message_vision(WHT"$NĿ��Ϊ�������ţ��⶯��ҡ��\n"NOR, target);
	    buff = 
			([
				"caster": me,
				"who":   target,
				"type":  "lowresist-kee",
				"att":	 "curse",
				"name":	"�����廨�������Գ�",
				"buff1":"apply/intelligence",
				"buff1_c": -10,
				"buff2": "apply/composure",
				"buff2_c": -10,	
				"buff3": "resistance/kee",
				"buff3_c": -10,  
				"time":    duration,
				"buff_msg": "",
				"disa_msg":WHT"$N"NOR WHT"���������ڻ���������\n"NOR,
				"disa_type": 1,
			]);
		ANNIE_D->buffup(buff);	
    }	else
        	message_vision(YEL"$N��Ϣ��������Ϊ������\n"NOR, target);	
	
	me->add_temp("apply/herb",-amount);
		
	return 1;

}
