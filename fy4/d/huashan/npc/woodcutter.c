// woodcutter.c
inherit NPC;

void create()
{
        set_name("�����Է�", ({"woodcutter"}) );
        set("gender", "����" );
        set("age", 26);
        set("agi",30);
        set("per", 10);
        set("long",
		"�Է��������Ŀ�����ǰ�Ĵ�����\n"
		);
        set("combat_exp", 100000);
        set_skill("move", 150);
        set_skill("parry", 150);
	set_skill("dodge", 160);
        set_skill("axe",150);
	setup();
	carry_object("/obj/weapon/woodaxe")->wield();
	carry_object("/obj/armor/cloth")->wear();  
}
