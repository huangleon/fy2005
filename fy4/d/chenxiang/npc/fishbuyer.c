// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("�����С����", ({ "fishbuyer" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",20);
        set("chat_chance", 5);
        set("chat_msg", ({
                "�����С�����ʵ���������ô����\n",
                "�����С�����������һ����������\n",
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
}
