// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("ӭ��ɮ", ({ "welcome bonze","bonze" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("age", 32);
        set("long", "һ��Ц������˹����µ�ӭ��ɮ��\n");
        set("combat_exp", 1000+random(5000));
        set("attitude", "friendly");

        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "ӭ��ɮ����˫�ƺ�ʮ��Ц������ӭ����ӭ��\n",
		"ӭ��ɮ˵����ʩ�������ɱ��̫���ˣ�\n",
		"ӭ��ɮЦ����ʩ����ʩ����һ��Ҫ���ʩ�ᣡ\n",
	}) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
}
