// worker.c

inherit NPC;

void create()
{
        set_name("�ŷ�", ({ "ya fang", "fang" }) );
        set("gender", "Ů��" );
        set("age", 9);
	set("title","С��ͯ");
        set("long", "�����С��ͯ���������䡣 \n");
        set("combat_exp", 7000);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);

	setup();
        carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/flower")->wield();
}

