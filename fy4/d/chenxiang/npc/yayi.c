// garrison.c

#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("��������", ({ "yayi", "ya" }) );
        set("long",
                "�������õ����ۣ�ǧ��Ҫ������\n");

        set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("group","officer");       
        set("combat_exp", 5000000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
"�������۵��������������������䡫������\n"
        }) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fumostaff",1);
        setup();
        carry_object(AREA_JINAN"npc/obj/yafu")->wear();
        carry_object(AREA_JINAN"npc/obj/sawei")->wield();
}

