inherit SMART_NPC;

void create()
{
//	string *name = ({"��","��","ʱ","��","��","��","��","��","��","��","��","ʷ"});
        set_name("һ��", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
		create_family("������", 18, "����");
        set("long", "���������µĺ��С�\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 3500000);
        set("attitude", "friendly");

        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"˵������ľ��������õģ�\n",
        }) );
    
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(50) :),
	     }) ); 		
	
		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","liuxing-hammer",1);
		
		setup();
		carry_object(__DIR__"obj/monk_cloth")->wear();
		carry_object(__DIR__"obj/hammer")->wield();
}
