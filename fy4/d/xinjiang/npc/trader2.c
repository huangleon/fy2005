inherit NPC;
void create()
{
        set_name("����������", ({ "wulapo trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ��˿��֮·���̵����ˡ�\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
	set("env/wimpy", 50);
        set_skill("shuaijiao", 30);
	set_skill("unarmed",40);
	map_skill("unarmed", "shuaijiao");
	set_skill("blade",100);
        set("chat_chance", 30);
        set("chat_msg", ({
                "�����૵����Ҳ�����·�˰ɣ�\n",
                "���˵�����˵��ɽ��һ����ŵ�һ����ѩ���������֣�\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "���˽е���ɱ����Ҫ�����ģ�\n",
                (: random_move :),
        }) );

	
	setup();
	add_money("coin", 5);
	carry_object(__DIR__"obj/knife")->wield();
	carry_object(__DIR__"obj/carpet")->wear();
}

