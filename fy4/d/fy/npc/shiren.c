// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_poem();
void create()
{
        set_name("����ʫ��", ({ "nomadic bard", "bard"}) );
        set("gender", "����" );
        set("age", 22);
        set("long", "����һλС�вŻ���ʫ�ˣ����ڹ������Ƴǡ�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
	set_skill("dodge", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ʫ�˿��˿����Ƴ�̾�����óǣ��óǣ�\n",
                "����ʫ��������ȥ���ƺ����ڴ򸹸塣\n",
        }) );
        set("inquiry", ([
                "�����޸�" : (: give_poem :),
                "poem" : (: give_poem :)

        ]));
	setup();

        carry_object("/obj/armor/cloth")->wear();
}

int give_poem()
{
	object obj;
	if( !query("given"))
	{
		command("say ��Ȼ����ҵ�ʫ����˳�ݣ����׾�������ɣ�\n");
		obj = new(__DIR__"obj/poem");
		obj->move(this_player());
		set("given",1);
	}
	else
		command("say ��֪����ܳ���ң����һ�Ҫһ�������д����ʫ��\n");
	return 1;
}

void reset()
{
	delete("given");
}
