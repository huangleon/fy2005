inherit NPC;

void create()
{
        set_name("����", ({ "old man", "man" }) );
        set("gender", "����");
        set("age", 54);
        set("long",
		"��λ�������������Եõس��ź��̡�\n"
	);
	set_skill("dagger", 10+random(50));
	set("combat_exp",2000);
        setup();
	carry_object(__DIR__"obj/yandou")->wield();
	carry_object("/obj/armor/cloth")->wear();
}
