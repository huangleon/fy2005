#include <ansi.h>
inherit MAZE_NPC;


void create()
{
        set_name("������", ({ "mind bug", "bug" }) );
        set("race", "Ұ��");
        set("maze","cave");
        set("class","taoist");
        set("age", 3);
        set("long", "����һֻ���޵��˵������˼�����Ĺ����ޣ����ס�˵Ļ��ǡ�\n"); 
        set("combat_exp",1400000);
		if (!random(10))	set("attitude","aggressive");
		set("target_name","������");
	        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",150,130,0,"/obj/weapon/","fighter_w","necromancy",1);
	
        setup();
}
