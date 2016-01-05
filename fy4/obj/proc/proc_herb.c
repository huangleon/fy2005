#include <ansi.h>


mixed hit_ob(object me, object victim, int damage_bonus)
{	
	int amount, proc;
	string msg;
	object weapon = me->query_temp("weapon");
	
	if (!weapon || weapon->query_temp("herb/owner")!= me)	return "";
	
	proc = weapon->query_temp("herb/proc_rate");	
	if (ANNIE_D->check_buff(me,"khl-atk-stance")>0)
		proc = proc * 15/10 ;
	
	amount = COMBAT_D->magic_modifier(me, victim, weapon->query_temp("herb/proc_type"),
				weapon->query_temp("herb/proc_amount"));

	switch (weapon->query_temp("herb/proc_type")){
		case "kee":		msg = HIB"$n�˿ڴ�һ���������ƺ�����$N"+weapon->name()+HIB"�ϵĶ���\n"NOR;
						break;
		case "sen":		msg = MAG"$n�˿ڴ�һ���������ƺ�����$N"+weapon->name()+ NOR MAG"�ϵĶ���\n"NOR;
						break;
		case "gin":		
		default:		msg = YEL"$n�˿ڴ�һ���������ƺ�����$N"+weapon->name()+NOR YEL"�ϵĶ���\n"NOR;
	}
	
	if (proc > random(100)) 
	{		
		victim->receive_damage(weapon->query_temp("herb/proc_type"),amount, me);
        return msg;
    } else
       	return "";
}
