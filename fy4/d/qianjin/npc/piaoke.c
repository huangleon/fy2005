
inherit NPC;

void create()
{
        set_name("���ο�", ({ "piaoke", "ke"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�ʷ����ֵĴ��ο�\n");
        set("combat_exp", 50000);
	set_skill("dodge", 100);
	set_skill("unarmed", 120);
        set("chat_chance", 10);
        set("chat_msg", ({
"���οͻ�ͷ�����ʲô��ƨ�����ϰ˽�������ʲô�˲���ģ��������¶������ԣ�\n",
		(: random_move :)
        }) );
	
	setup();
	add_money("coin", 50);
        carry_object("/obj/armor/cloth")->wear();
}

