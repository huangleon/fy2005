#include <ansi.h>
inherit MAZE_NPC;


void create()
{
        set_name("��", ({ "devil" }) );
        set("race", "Ұ��");
        set("class","taoist");
        set("maze","cave");
        set("age", 3);
        set("long", "����һֻ���޵��˵������˼�����Ĺ����ޣ����ס�˵Ļ��ǡ�\n"); 
        set("target_name","������");
        set("combat_exp",1800000);
		set("attitude","aggressive");
		        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",180,130,0,"/obj/weapon/","fighter_w","necromancy",1);
	
        setup();
}

