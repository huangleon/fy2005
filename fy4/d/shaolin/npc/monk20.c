// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�������", ({ "shaolin monk", "monk"}) );
        create_family("������", 20, "����");
        set("gender", "����" );
        set("age",random(20)+ 32);
	set("nickname",HIW"��"NOR);
        set("long", "���������µĽ�ɮ��\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        
        set_skill("sword", 200);
	set_skill("suiyuan-sword",160);
	set_skill("move",200);
	set_skill("force",200);
	set_skill("dodge",150);
	set_skill("puti-steps",150);
	set_skill("parry",160);
	set_skill("unarmed",200);
	set_skill("dabei-strike",200);
	map_skill("sword","suiyuan-sword");
	map_skill("dodge","puti-steps");
	map_skill("parry", "suiyuan-sword");
	map_skill("move","puti-steps");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		name()+"Ц��������������Ұ��\n",
                (: perform_action, "sword.yiqiesuiyuan" :),
        }) );
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"�趯������ȫ���������������һ�ﳾ����\n",
                name()+"һ��С�ģ�����÷��׮�ϵ�������\n",
                name()+"����һ����ש��Ȼ���Լ���ǰ���ȥ��������שӦ�����ѣ�\n",
		name()+"�����а�ʮ��Ĵ�ˣ����һ�仨���Ƶġ�\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk20_cloth")->wear();
	carry_object(__DIR__"obj/monk_sword")->wield();
	
}

