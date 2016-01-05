// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("׳�����", ({ "shaolin monk", "monk"}) );
        create_family("������", 18, "����");
        set("gender", "����" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
		set("nickname",HIG"ר��һ��"NOR);
        set("long", "����������ר���о������书��Ѱ���ƽ���ɾ��еĺ��У�\n");
		set("vendetta_mark","shaolin");
        
        set("combat_exp", 4500000);
        set("attitude", "friendly");
                       
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"̾�������ģ���������ħ������ʽ�����Ǻ���������\n",
                name()+"Ц����Ҳ��֪�����񺯣�����ü������ڽ���
���㣡���ɽ���书һ�����в���ʮ��������\n",
                name()+"����������Ů��Ҳ������ˣ�\n",
				name()+"�е������ڱ����ҳ������ˣ�\n"
        }) );
	
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(10) :),
     }) ); 		

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fumostaff",1);
	setup();
	carry_object(__DIR__"obj/monk20b_cloth")->wear();
	carry_object(__DIR__"obj/stick")->wield();
}
