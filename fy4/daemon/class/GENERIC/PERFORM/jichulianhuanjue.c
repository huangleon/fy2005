/*
		"tiandirenmojue":	([
			"e_id":	"tiandirenmo",
			"c_id":	"�����ħ",
			"fixed_atk":	500,
			"fixed_dmg":	300,
			"self_busy":	4,
			"cdt":			180,	// individual_cdt
			"g_cdt":		60,		// global_cdt
			"weapon":		1,
		]),
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg;
		string p_name;
		mapping perform;
		int level, fixed_atk, fixed_dmg;
		
		p_name = "jichulianhuanjue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
							
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("���Ƴ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		fixed_atk = perform["fixed_atk"] * level /139;
		fixed_dmg = (perform["fixed_dmg"]-320)*level/139 + (level -100)*8;
		
//		if (fixed_atk<300)	fixed_atk = 200 + level ;
//		if (fixed_dmg<250)	fixed_dmg = 150 + level;
		
		me->set_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",fixed_atk);
		me->add_temp("marks/fixed_dmg",fixed_dmg);
		me->set_temp("marks/no_parry_busy_pfm",1);
		me->add_temp("marks/full_hit_damage",1);
		
		target->set_temp("no_check_pfm_win",1);			
		msg = HIR  "\n\n$N"HIR"�ӳ���������еľ�����ص�һʽ�������ƣ�����������������\n"NOR;
    	message_vision(msg, me, target);
    		
    	msg=HIR"��սƪ��$N"HIR"����$w"HIR"ֱ��$n��" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    	target->set_temp("skip_damage_record",1);
    	
    		msg = HIY  "ʤսƪ��\n$N"HIY"����$w"+HIY"б��$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIW  "��սƪ��\n$N"HIW"����$w"+HIW"ƽ��$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIG  "��սƪ��\n$N"HIG"����$w"+HIG"�ῳ$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIM  "��սƪ��\n$N"HIM"����$w"+HIM"�ݶ�$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	msg = HIC  "��սƪ��\n$N"HIC"����$w"+HIC"����$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIB  "��սƪ��\n$N"HIB"����$w"+HIB"����$n��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    		msg = HIR  "��սƪ��\n$N"HIR"����$w"+HIR"�ӽ����������$n"+HIR"ɱȥ��" NOR;
    		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        
    	
    	me->delete_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",-fixed_atk);
		me->add_temp("marks/fixed_dmg",-fixed_dmg);
		me->add_temp("marks/full_hit_damage",-1);
    	
    	if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		me->delete_temp("marks/no_parry_busy_pfm");
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);


//		write("fixed_atk = "+ fixed_atk + " fixed_dmg = "+ fixed_dmg + "\n");
				
		return 1;
}
