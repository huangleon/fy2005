// scavenger.c

inherit NPC;

void create()
{
	set_name("�����õ�", ({ "scavenger" }) );
	set("gender", "����" );
	set("age", 47);
	set("long", "����˲����Լ������ã�����Ҳ�������ò�����\n");
	set("combat_exp", 10);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		"�����õ�ߺ�ȵ����ա��ơ��á��ġ�\n",
		"�����õ��������������֪��˵Щʲ�ᡣ\n",
		"�����õ�����׽ס�����ϵ�ʭ�ӣ�һ�Ųȵñ��ġ� \n",
		(: random_move :)
	}) );
	carry_object("/obj/armor/cloth")->wear();
	add_money("coin", 5);
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say ��л��λ" + RANK_D->query_respect(me) + "��");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}
