// dtz.c

inherit NPC;

void create()
{
	set("title","ƥ������");
        set_name("��������", ({ "mf tester","tester" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "�ҿ������Ұ�����򰡴�\n");

        set("combat_exp", random(10000));

        set_skill("unarmed", 20);
        set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
	add_money("silver", 1);
        carry_object("/obj/armor/cloth")->wear();        
}

void die()
{
	//Ŀǰ�ɹ�����100	
	MF_D->new_vo(random(100),"cloth")->move(this_object());
	::die();
}