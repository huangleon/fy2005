#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("�����", ({ "crazy taoist","taoist" }) );
        set("class","taoist");
        set("age", 53);
        set("long", "������˰���ߣ���ݺݵص����㡣\n"); 

        set("maze","cave");
        set("combat_exp",2400000);
		set("attitude","aggressive");
		        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	
    	auto_npc_setup("wang",180,145,1,"/obj/weapon/","fighter_w","necromancy",1);
	
        setup();
}

