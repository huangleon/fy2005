
inherit NPC;

void create()
{
        set_name("С԰��", ({ "young gardener", "gardener" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "һλ�����С԰��\n");
		set("str", 12);
		set("int", 24);
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/scissors")->wield();
}

