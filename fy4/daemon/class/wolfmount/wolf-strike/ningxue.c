#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, dmg, mod, duration;
	mapping buff;
	
    if(me->query("class")!="wolfmount")
    	return notify_fail("ֻ����ɽ���Ӳ���ʹ������Ѫ���ľ�����\n");
    	
	extra = me->query_skill("wolf-strike",1) ;
	if(extra < 200 || me->query_skill("summonwolf",1)<200 ) 
		return notify_fail("����Ѫ����Ҫ200�������ǰ���ȭ�ͻ�������\n");
	
	duration = me->query("timer/pfm/wm_ningxue")+ 90 -time();
	if (duration>0)
		return notify_fail("����Ѫ������Ԫ������Ҫ"+duration+"���Ӻ�����ٴ����á�\n");
    		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(WHT"����Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

	msg = WHT "$N"WHT"˫צ�ػ�����һ�����Σ�һ��ɭɭ������ֱ��$n��\n" NOR;
	
	// atk 200*3
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra*3);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
    me->add_temp("apply/attack",-extra*3);
        	    	
	me->perform_busy(1);
	
	if (!target || !target->query_temp("damaged_during_attack"))
		return 1;
    
    if (ANNIE_D->check_buff(me, "wolf-berserk"))
    	return 1;
    			
    msg = HIR"$Nһץ���֣�ʮָ��Ѫ���죬�����������ȣ����з������˵ĵͺ�����\n"NOR;    
    buff =
			([
				"caster": me,
				"who":    me,
				"type": "wolf-berserk",
				"att":	"bless",
				"name":	"���ǰ��ơ���Ѫ",
				"buff1":  "apply/parry",
				"buff1_c":100,
				"buff2":  "apply/attack",
				"buff2_c": 100,
				"buff3":  "apply/dodge",
				"buff3_c": 100,			
				"time":  40 ,
				"buff_msg": msg,
	]);
			
	ANNIE_D->buffup(buff);
	me->set("timer/pfm/wm_ningxue",time());
	   	
    return 1;
}
