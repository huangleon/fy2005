// worker.c

inherit NPC;

void create()
{
        set_name("�ɻ��", ({ "little girl", "girl" }) );
        set("gender", "Ů��" );
        set("age", 9);
        set("long", "�����СŮ��������ˣ�š�\n");
        set("combat_exp", 12000);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);

        set("inquiry", ([
		"С��" : "��Ҫ������ɽȥ�ʡ�", 
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/flower")->wield();
}

