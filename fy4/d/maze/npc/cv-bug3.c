#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("��", ({ "mind bug", "bug" }) );
        set("race", "Ұ��");
        set("class","taoist");
        set("age", 3);
        set("long", "����һֻ���޵��˵������˼�����Ĺ����ޣ����ס�˵Ļ��ǡ�\n"); 
		set("maze","cave");
        set("combat_exp",1900000);
		set("target_name","������");
			        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",180,135,1,"/obj/weapon/","fighter_w","scratmancy",1);
	
        setup();
}

