// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit SMART_NPC;
#include <ansi.h>
void create()
{
        set_name("�������", ({ "shaolin monk", "monk"}) );
        create_family("������", 20, "����");
        set("gender", "����" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
		set("nickname",HIY"��ɮ"NOR);
        set("long", "���������µĹ�ɮ��\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 4000000);
        
        set("attitude", "friendly");
		      
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"ͷһƫ�������˲��˯���ڵ��ϡ�\n",
                name()+"��ɫ��ׯ�����������дǡ�\n",
                name()+"˫��΢�գ��촽΢��������\n",
		name()+"ȫ�����һ��ʯͷһ����һ��������\n"
        }) );
        
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
     	}) ); 		

	auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","fumostaff",1);    
	setup();
	carry_object(__DIR__"obj/monk20_cloth")->wear();
	carry_object(__DIR__"obj/stick")->wield();
}

