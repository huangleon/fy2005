inherit NPC;

void create()
{
	set_name("��ɽ��", ({ "labor" }) );
	set("gender", "����" );
	set("age", 47);
	set("long", "�����������ɽ��������Ϊ���ġ�\n");
	set("combat_exp", 70000);
	
	set_skill("staff",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		(: random_move :)
	}) );
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/biandan")->wield();
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
