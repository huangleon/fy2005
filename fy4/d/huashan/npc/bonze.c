// woodcutter.c
inherit NPC;

void create()
{
        set_name("����ɮ", ({"bonze", "travel bonze"}) );
        set("gender", "����" );
        set("age", 36);
        set("long",
		"һ�������ķ��Ľ���ɮ��\n"
		);
        set("combat_exp", 120000);
        set_skill("move", 150);
        set_skill("parry", 150);
	set_skill("dodge", 160);
	set_skill("unarmed",150);
	setup();
	carry_object("/obj/armor/cloth")->wear();  
	carry_object("/obj/armor/sandal")->wear();
}
