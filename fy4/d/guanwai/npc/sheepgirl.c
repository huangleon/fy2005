// worker.c

inherit NPC;

void create()
{
        set_name("����Ů", ({ "sheep girl", "girl" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "һ��������ã������󷽵���Ů�� \n");
        set("combat_exp", 17000);
	set("per", 30);
        set("attitude", "friendly");
        set_skill("whip", 40);
        set_skill("parry", 45);
	set_skill("dodge", 100);
	set_skill("snowwhip", 20);
	map_skill("whip", "snowwhip");
	map_skill("parry", "snowwhip");

	setup();
        carry_object(__DIR__"obj/skirt")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}

