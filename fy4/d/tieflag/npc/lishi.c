// zhuo.c
inherit NPC;


void create()
{
        set_name("����ʿ", ({"li shi"}) );
        set("gender", "����" );
        set("age", 26);
        set("agi",30);
        set("per", 10);
    	set("no_arrest",1);
        set("str",200);
        set("long",
		"����ʿ�ľ����Ѿ�������������ơ�\n"
		);
        set("force_factor", 0);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("eff_gin", 1000);
        set("eff_kee", 1000);
        set("eff_sen", 1000);
        set("gin", 1000);
        set("kee", 1000);
        set("sen", 1000);
        set("max_force", 1000);
        set("force", 1000);
        set("combat_exp", 699999);
        set("score", 10000);
        set_skill("move", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("axe",200);
	setup();
	carry_object(__DIR__"obj/xuanaxe")->wield();
        carry_object("/obj/armor/cloth")->wear();  
}
