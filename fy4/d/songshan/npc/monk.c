// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�պ�", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(10)+ 32);
        set("long", "���������³��⻯ի�ĺ��С�\n");
	set("vendetta_mark","shaolin");
        create_family("������", 23, "����");
        set("combat_exp", random(10000)+10000);
        set("attitude", "friendly");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
		"�պ����˸���ŵ������ʩ��������Ǯ�ɣ���\n",
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :)
        }) );
        set_skill("unarmed", 5+random(40));
	set_skill("dabei-strike",random(40)+5);
	map_skill("unarmed","dabei-strike");
	set_skill("move",40);
	set_skill("force",20);
	set("force",100);
        set("max_force",100);
	set("force_factor",2);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/bowl");
}

int accept_object(object me, object obj)
{
command("sigh");
command("say �����ѹ�ѽ��\n");
command("say ���ڵĲؾ�¥���Ƕ��飬�������ڶ��������𷣵������ʮ�꣡\n");
command("thank " + me->query("id"));
return 1;

}
