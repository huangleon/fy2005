#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon;
		int level, fixed_atk, fixed_dmg;
		
		p_name = "tianwaifeixianjue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
								
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("��������ɡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		
		level = F_LEVEL->get_level(me->query("combat_exp"));
		fixed_atk = perform["fixed_atk"] * level /139;
		fixed_dmg = (perform["fixed_dmg"]-320)*level/139 + (level -100)*8;
		
		me->set_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",fixed_atk);
		me->add_temp("marks/fixed_dmg",fixed_dmg);
		me->add_temp("marks/full_hit_damage",1);
		
//		weapon=me->query_temp("weapon");
	
		target->set_temp("no_check_pfm_win",1);
		target->add_temp("buff/no_abs",1);
//		msg = HIR  "$N���ƶ��䣬ʹ�����ɽ����еľ��裭����������ɡ������е�"+ weapon->name() +HIR"����һ�����磬�����Ļ���$n��\n" NOR;
		msg = HIR  "$N���ƶ��䣬ʹ�����ɽ����еľ��裭����������ɡ������еı�������һ�����磬�����Ļ���$n��\n" NOR;
		message_vision(msg, me,target);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"","����");
		target->set_temp("skip_damage_record",1);
        
        msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"����");
        msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"����");
        msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"����");
        msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"����");
        msg = HIY "������磬ת˲���ţ�$N����ͻת�������طɣ�" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg,"����");
        
    	
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
			target->add_temp("buff/no_abs",-1);
		}
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		return 1;
}

