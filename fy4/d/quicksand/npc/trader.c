
inherit NPC;

void create()
{
        set_name("����", ({ "trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ�������������ˡ�\n");
        
        set("combat_exp", 20000);
        set("attitude", "friendly");
		
		set("env/wimpy", 50);
        set("agi", 2);
	
        set_skill("unarmed", 30);
		set_skill("iron-cloth", 50);
		set_skill("bloodystrike", 20);
		map_skill("unarmed", "bloodystrike");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������๼��˵�����Ҽ������ڴ�Į����ɳ�У�\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
                "����˵���������ҴӴ�Į���������ھ�ȻҪ����·�ߣ�\n",
        }) );

	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/teablock");
	carry_object(__DIR__"obj/perfume");
}
