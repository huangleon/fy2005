// greeting_bonze.c

inherit NPC;

void create()
{
        set_name("֪��ɮ", ({ "greeting bonze", "bonze" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("age", 37);
        set("str", 26);

        set("long",
                "���֪��ɮ��ɫ�Ͱ�����Ȼ�����еĵ�λ���ߣ�����������������һ��\n"
                "ֵ�������ĸо���\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");

        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

int accept_fight(object me)
{
        command("say �����ӷ�Сɮ�书��΢��������ǡ�\n");
        return 0;
}
