inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();

void create()
{
	object weapon;
    	set_name("¾Õ", ({ "ju"}) );
    	set("nickname", BLU"Î´"NOR);
    	set("gender", "Å®ÐÔ" );
    	set("class","beggar");

		set("title",YEL"´ó¹âÃ÷½Ì"NOR);
    
    	set("reward_npc", 1);
    	set("difficulty", 6);
    
    	set("age", 34);
    	set("per", 35);

		set("busy_immune",4);
    	set("attitude","friendly");

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: smart_fight() :),
             }) );

    	set("combat_exp", 6100000);
    
    	set_skill("perception", 200);
    	set_skill("move", 200);
    	set_skill("parry",200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("unarmed",200);
    	set_skill("stormdance",170);
    	set_skill("nine-moon-claw",200);
    	set_skill("divineforce",150);
    	set_skill("staff",250);
    	set_skill("dagou-stick",200);
    	
    	map_skill("dodge", "stormdance");
    	map_skill("force", "divineforce");
    	map_skill("unarmed", "nine-moon-claw");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dagou-stick");
    	
    	
    setup();


		weapon=carry_object("/obj/weapon/fist");
        weapon->set_name("ÇïÐ·Ç¯", ({ "claw" }) );
		weapon->set("value",0);
		weapon->set("level_required",200);
		weapon->set("weapon_wielded","³Ö");
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("¶ì»ÆÐåÈ¹", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{


	if (ccommand("perform force.check_gspm"))
		ccommand("perform force.guishenpomie");
	else
		ccommand("perform force.zombify");
	return ;
}



/*
 
               (\~~~/)            
               ( £®£®)        

               (_____)~£®      
   
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 10.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/
