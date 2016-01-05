// farmer.c

inherit NPC;

void create()
{
	set_name("ũ��", ({ "poor farmer","farmer" }) );
	set("gender", "����" );
	set("age", 33);
	set("long", "�㿴��һλ��ɫ��ڵ�ũ��\n");
	set("combat_exp", 20);
	set("attitude", "friendly");
	set("env/wimpy", 60);
	set("chat_chance_combat", 50 );
	set("chat_msg_combat", ({
		"ũ��е���ɱ���ģ�ɱ���ģ�\n",
		"ũ��е����������ģ����컯���´���ģ�\n",
		(: command, "surrender" :),
	}) );
	setup();
	carry_object(__DIR__"obj/raincoat")->wear();
	carry_object(__DIR__"obj/sandals")->wear();

}
