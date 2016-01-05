// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("��ɮ", ({ "shaolin monk", "monk"}) );
        create_family("������", 17, "����");
        set("gender", "����" );
        set("age",random(30)+ 62);
		set("nickname",HIR"����ɮ"NOR);
        set("long", "���������»��µ���ɮ��\n");
		set("vendetta_mark","shaolin");
        set("combat_exp",5200000);
        set("attitude", "friendly");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"��Ŀ�����ļ�ʦ���ڴ���ڣ����˲������ڡ�\n"
        }) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(40) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
		setup();
		carry_object(__DIR__"obj/monk20c_cloth")->wear();
}
