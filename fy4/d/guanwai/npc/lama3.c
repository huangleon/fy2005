
inherit SMART_NPC;

void create()
{
	set_name("���²���", ({ "zang ni", "ni"}) );
	set("gender", "Ů��" );
	set("age", 25);
	set("long", @LONG
һ�������µĲ��ᡣ
LONG
);
	set("class","lama");
	
	set("attitude", "peaceful");
        set("combat_exp", 16000);
        create_family("������", random(4)+22, "����");
        
        set_skill("unarmed", 50+random(10));
        set_skill("bloodystrike", random(50)+20);
        set_skill("force", 40);
	set_skill("iron-cloth", 40+random(10));
	map_skill("unarmed", "bloodystrike");
	
		set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );


	
	
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();

        carry_object(__DIR__"obj/redcloth2")->wear();
}
