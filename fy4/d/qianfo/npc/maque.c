// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("����С��ȸ", ({ "maque", "que" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 3);
	set("long", "����һֻ����С��ȸ��\n");
	set("attitude", "peaceful");
	set("combat_exp",5000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"С��ȸ��ߴ����ߴߴ���������˼���\n",
        }) );
	set_temp("apply/attack", 60);
	set_temp("apply/dodge",40);
	setup();
}
