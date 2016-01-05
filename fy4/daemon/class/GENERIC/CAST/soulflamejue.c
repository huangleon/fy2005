// void_sense.c

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object weapon, *inv, env;
		int i, damage,level;
						
		p_name = "soulflamejue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
								
		if(!me->is_fighting())
			return notify_fail("��ħ�����꡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		if (me->query("mana")<100)
			return notify_fail("������Ҫ100�㷨����\n");
		if (userp(me))
			me->add("mana",-100);
		
		message_vision(NOR CYN"$N��ɫ������������������������������־�����ǰ������������״�� \n" NOR, me);
		message_vision(HIB"�������ĵ�����·��ܵ��ٻ��ӵ������ڶ��� \n$N��Χ��ʱ����˿ֲ����˼������� \n"NOR, me);
		
		me->set_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",perform["fixed_atk"]);
		me->add_temp("marks/fixed_dmg",perform["fixed_dmg"]);
		
		env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
           	if( inv[i]==me ) continue;
           	if( inv[i]->is_corpse() ) continue;
			if( !inv[i]->is_character()) continue;
            if( !inv[i]->is_fighting(me)) continue;              	
			message_vision(NOR BLU "\n�䶯�������$N���������ζ�����\n"NOR, inv[i]);
            if (COMBAT_D->do_magic_attack(me, inv[i], "spells", "sen", 0)) {
				message_vision(HIC "\nһ�����䶯�����������߰������$N��\n"NOR, inv[i]);
					
					// better than thunderbolt 690, slightly better than single bolt 600+ random(540)
					// 1500
					
					level = F_LEVEL->get_level(me->query("combat_exp"));
					damage = (1500 -320) *level /139 + (level- 100)*8;
					damage = COMBAT_D->magic_modifier(me, inv[i], "sen", damage);   
					inv[i]->receive_damage("sen",damage,me);
					inv[i]->receive_damage("gin",damage,me);
					COMBAT_D->report_status(inv[i]);
					COMBAT_D->win_lose_check(me,inv[i],damage);
			} else {
					message_vision(YEL "\n$N����Ծ�������˶��߰�Ļ��档\n"NOR, inv[i]);
			}  	                	
        }
        
        me->delete_temp("marks/r1_pfm",perform["e_id"]);
		me->add_temp("marks/fixed_atk",-perform["fixed_atk"]);
		me->add_temp("marks/fixed_dmg",-perform["fixed_dmg"]);
		        			
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		return 1;
}

