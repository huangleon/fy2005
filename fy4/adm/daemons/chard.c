// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// chard.c
//	-- Modified by Silencer@fy4, added time restriction and no-corpse message.

#include <race.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
        string race;
        mapping my;
        if( !stringp(race = ob->query("race")) ) {
                race = "����";
                ob->set("race", "����");
        }
                
        switch(race) {
                case "����":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "��ħ":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "Ұ��":
                        BEAST_RACE->setup_beast(ob);
                        break;
                case "����":
                        STOCK_RACE->setup_animal(ob);
                        break;
                case "����":
                        BIRD_RACE->setup_animal(ob);
                        break;
                case "����":
                        FISH_RACE->setup_animal(ob);
                        break;
                case "����":
                        SNAKE_RACE->setup_animal(ob);
                        break;
                case "����":
                        INSECT_RACE->setup_animal(ob);
                        break;
                case "��":
                        DRAGON_RACE->setup_animal(ob);
                        break;
                case "Ԫ��":
                        ELEMENT_RACE->setup_element(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }

        my = ob->query_entire_dbase();

        if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
        if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
        if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

        if( !ob->query_max_encumbrance() )
                ob->set_max_encumbrance( my["str"] * 20000 );

        ob->reset_action();
}

varargs object make_corpse(object victim, object killer) {
	int i;
	object corpse, *inv, *allowed, murderer, *team, ghost_item;
	
//	allowed = ({});
	if (!userp(victim) && stringp(victim->query("NO_CORPSE"))) {
		message_vision(victim->query("NO_CORPSE"),victim); //����NPC�в�����ʬ�������
	}	
	else if(!victim->is_ghost() && !victim->is_zombie()) {
		corpse = new(CORPSE_OB);
		corpse->set_name(victim->name(1) + "��ʬ��", ({ "corpse" }) );
		corpse->set("long", victim->long(1) + "Ȼ����" 
				+ gender_pronoun(victim->query("gender")) 
				+ "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
		corpse->set("age", victim->query("age"));
		corpse->set("gender", victim->query("gender"));
		corpse->set("race", victim->query("race"));
		corpse->set("family", victim->query("family"));
		corpse->set("victim_name", victim->name(1));
		corpse->set("victim_id", victim->query("id"));
		// Below is set to make it easier to implement revive
		if (userp(victim))	corpse->set("victim_player",1);
		// below two lines are to prevent unlimitted pet corpse burning.
		if (victim->query("possessed")) corpse->set("possessed",1);
		if (victim->query("owner")) corpse->set("possessed",1);
		// below two lines are to prevent picking up player corpse.
		corpse->set_weight(victim->query_weight()  * (userp(victim)? 100: 1)); 
		corpse->set("player",(userp(victim))?1 :0); 
		corpse->set_max_encumbrance(victim->query_max_encumbrance());
		
		//  No need to revive, no loss anyway
		if (victim->query("combat_exp")<= 12000)
			corpse->set("already_revived");
		
		// below are to setup the time restriction for picking items/corpse.see get.c
		
		corpse->set("freeze", victim->query("real_boss")? 1: 0);
		
		if (!objectp(murderer = victim->query_max_damage_dealer())) 
			murderer = victim->query_temp("last_damage_from");
				
		if (objectp(murderer)) {				
			if (objectp(murderer->query("possessed")))	
				murderer = murderer->query("possessed");
			if (arrayp(team = murderer->query_team()) && sizeof(team))
				allowed = team;
			else
				allowed = ({ murderer });
			corpse->set("allow_to_loot",allowed);
			corpse->set("killer",murderer);
		}
		corpse->set("death_time",time());
		
		corpse->set("hp",victim->query("max_kee")+victim->query("max_gin")+victim->query("max_sen"));
		corpse->set("exp",victim->query("combat_exp"));
		corpse->set("level",F_LEVEL->get_level(victim->query("combat_exp")));
		
		corpse->move(environment(victim));
	} else if (victim->is_ghost()) {
		message_vision("�˵�һ����$N����һ�����̱��紵ɢ�ˡ�\n", victim);				
	} else {
		message_vision("$N�����ص�����������Ϊһ̲Ѫˮ��\n", victim);		
	}
	
	// Don't let wizard left illegal items in their corpses.
	if(!wizardp(victim) && victim->query("timer/insurance")+ 259200< time() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);	//��Ʒ��������Զ�ת����
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if(!inv[i]->query("no_drop")) {
				if(objectp(corpse)) {
					if((string)inv[i]->query("equipped")=="worn") {
						inv[i]->unequip();				
						inv[i]->move(corpse);
					} else if((string)inv[i]->query("equipped")=="wielded") {
						inv[i]->unequip();				
						inv[i]->move(corpse);
					} else {
						inv[i]->move(corpse);
					}	
				} else {
					if (inv[i]->query("ghostcurse_item"))
					{
						ghost_item = new("/obj/item/ghost_item");
						ghost_item->set("name",inv[i]->query("name"));
						ghost_item->set("unit",inv[i]->query("unit"));
						if (!ghost_item->move(environment(victim)))	
							destruct(ghost_item);
					} else
						inv[i]->move(environment(victim));	
				}				
			}
		}
	}
	return corpse;
}
