// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("ũ��Ů", ({ "nongnu" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",20);
	set("arrive_msg", "�ı����������˹���");
	set("leave_msg", "�ܿ���");
        set("chat_chance", 2);
        set("chat_msg", ({
                "ũ��ŮЦ��������һ���ߣ��ò�����\n",
                "ũ��Ů����ë������˼��¡�\n",
		 (: random_move :)

        }) );

	setup();
	carry_object(__DIR__"obj/jianzi");
	carry_object("/obj/armor/cloth")->wear();
}
