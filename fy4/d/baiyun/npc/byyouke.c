
inherit NPC;

void create()
{
	set_name("Ѱ�ɿ�", ({ "wandering visitor","visitor"}) );
	set("gender", "����" );
	set("age", 35);
	set("long", "һ��Ư���ĺ������ˣ��Ĵ�Ѱ���ʵ���\n");
	set("attitude", "peaceful");
        set("title", "һ�����");
        set("combat_exp", 750000);
        set_skill("unarmed", 100);
        set_skill("calligraphy", 120);
        set_skill("force", 50);
		set_skill("iron-cloth", 100);
		set_skill("dodge",100);
		set_skill("parry",100);
		set_skill("feixian-steps",100);
		map_skill("dodge","feixian-steps");
		map_skill("unarmed", "calligraphy");
    
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "\nѰ�ɿ��������������������������������˾����ںη��أ�\n",
        }) );

		setup();
        carry_object(__DIR__"obj/piyi")->wear();
 
}
