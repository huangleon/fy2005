
inherit NPC;

void create()
{
        set_name("׼�������", ({ "trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ��׼����������ˡ�\n");
        set("combat_exp", 50000);
        
        set("attitude", "friendly");

		set("env/wimpy", 50);
        set("agi", 2);
        
        set_skill("unarmed", 50);
		set_skill("iron-cloth", 100);
		set_skill("bloodystrike", 70);
		set_skill("parry",50);
		map_skill("unarmed", "bloodystrike");
        
        set("chat_chance", 2);
        set("chat_msg", ({
                "����˵������������ţ����������ˢ�ģ�\n",
                (: random_move :),
        }) );
        
        
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/teablock");
		carry_object(__DIR__"obj/perfume");
}

