// worker.c

inherit NPC;

void create()
{
        set_name("���ͽ", ({ "chanhui tu", "tu" }) );
        set("gender", "Ů��" );
        set("age", 19);
	set("title","��������");
        set("long", "һ��������������ͽ\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);
	

	setup();
        carry_object("/obj/armor/cloth")->wear();
}

