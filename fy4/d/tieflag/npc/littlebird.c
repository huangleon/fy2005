// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("Сɽȸ", ({ "bird", "little bird" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 1);
	set("long", "����һֻ�ÿɰ���Сɽȸ��\n");
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"Сɽȸ��ߴ����ߴߴ��������Ҫ�����ԡ�\n",
        }) );
	set_temp("apply/attack", 400);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",400);
	set("combat_exp",1000000);
	setup();
	carry_object(AREA_TIEFLAG"npc/obj/tongue",(["name":"Сɽȸ��"]));
}
