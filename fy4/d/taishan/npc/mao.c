#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("é������", ({ "mr da" }) );
        set("gender", "����");
	set("age",75);
        set("combat_exp", 1000000);
        set("long",
		"һ���׷��ԲԵ����˶��ѣ�û��ʲô�ر�ĵط���\n"
	);
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(80) :),
        }) );
    	    	
    	auto_npc_setup("wang",150,160,1,"/obj/weapon/","fighter_w","feixian-sword",1);
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
