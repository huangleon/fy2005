#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("����", ({ "imperial guard", "guard" }) );
        set("long",
                "һȺ�����ƻ����յ㻤����\n");
	set("cor",20);
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"�����ŵ�����ƽ�����������˾�������������\n"
        }) );

	auto_npc_setup("wang",180,140,0,"/obj/weapon/","fighter_w","taiji",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

