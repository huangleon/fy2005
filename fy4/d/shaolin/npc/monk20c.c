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
		set("nickname",HIR"��ͨ����"NOR);
        set("long", "����������ר���о������书��Ѱ���ƽ���ɾ��еĺ��С�\n");
		set("vendetta_mark","shaolin");
        set("combat_exp",5000000);
        set("attitude", "friendly");
        set("cor",20);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"̾����������������\n",
                name()+"Ц�������뿴��������ţ�\n",
                name()+"�������㿴Ҳû���ã�����츳������\n",
				name()+"���������Ѿ���ʮ����û����¥һ���ˣ�\n"
        }) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(15) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
		setup();
		carry_object(__DIR__"obj/monk20c_cloth")->wear();
}
