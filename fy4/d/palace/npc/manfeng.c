inherit SMART_NPC;

void create()
{
        set_name("������", ({ "manfeng" }) );
        set("gender", "Ů��" );
	set("long","���ǵ����ȹ�����Ů����һ���书�Ѿ����丸�洫��\n");
        
        set("age", 18);
        set("per", 58);
		set("no_arrest",1);
        create_family("������", 2, "����");
        set("fly_target",1);

        set("combat_exp", 9500000);
        
      	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","thunderwhip",2);
		setup();
		carry_object(BOOKS"skill/essencemagic_11")->wear();
		carry_object(__DIR__"obj/sidai")->wield();
}
