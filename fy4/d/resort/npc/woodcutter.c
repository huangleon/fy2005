// woodcutter.c

inherit NPC;

void create()
{
	set_name("�Է�", ({ "woodcutter" }) );
	set("gender", "����" );
	set("age", 26);
	set("long", "�㿴��һ����׳�Ĵ󺺣����ϴ�����ͨ�Է���·���\n");
	set("combat_exp", 3340);
	set("str", 30);
	set("chat_chance", 1);
	set("chat_msg", ({
		"�Է�˵������....����Խ��Խ���ù��ޡ�\n",
		(: random_move :)
	}) );
	set("env/wimpy", 10);
	setup();
	carry_object(__DIR__"obj/lumber_axe")->wield();
	carry_object("/obj/armor/cloth")->wear();
}
