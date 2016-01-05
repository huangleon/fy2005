#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("°¢ÀïÄ¾", ({ "eagle alimu", "alimu","eagle" }) );
        set("long", "Ë«Í·ÍºÓ¥°¢ÀïÄ¾£¬ÌìÉ½µÚÒ»É±ÊÖ¡£\n");
        set("nickname",HIG "Ë«Í·ÍºÓ¥"NOR);
        set("attitude", "heroism");
//        set("vendetta_mark", "authority");
//	set("vendetta_mark","pker");

	set("reward_npc", 1);
	set("difficulty", 25);
	set("combat_exp", 8000000);

        set("gender", "ÄÐÐÔ");
               
        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :)
        }) );
        

	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	        
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","mapo",2);
        setup();
        carry_object(__DIR__"obj/kacloth",([	"name": "ñÊñÈ",
    						"long": "Î¬Îá¶û×åÄÐ·þ£¬ÓÒñÅÐ±Áì£¬ÎÞÅ¦¿Û£¬ÓÃ³¤·½½íÔúÑü¡£\n",
    						"value": 2, 
    						 ]))->wear();    
}