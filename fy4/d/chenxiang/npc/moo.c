// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	object scoin;
	set_name("ĥ�˵���", ({ "moman" }) );
	set("gender", "����" );
	set("age", 47);
	set("long", "�������ר�Ű���ĥ���Ӻ��ϲ˵��ġ�\n");
	set("combat_exp", 3000);
	set("str", 27);
	
	set("chat_chance", 11);
	set("chat_msg", ({
		"ĥ�˵��ĸ���ߺ�ȵ���ĥ����ඡ��ϲ˵�������\n",
		(: random_move :)
	}) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/coin");
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say ��л��λ" + RANK_D->query_respect(me) + "��");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}
