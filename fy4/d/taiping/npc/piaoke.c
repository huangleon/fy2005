inherit SMART_NPC;

void create()
{
        set_name("�ϳ�����", ({ "buhua"}) );
        set("title","���ο�");
        set("gender", "����" );
        set("long", "����һλ�ʷ����ֵĴ��οͣ��ڽ�����ҲС���������ǡ�Ѫ���ھ֡��ĸ������ϳ�������\n");
		set("age",47);
	
		set("combat_exp", 6000000);
        
	      
        set("chat_chance", 1);
        set("chat_msg", ({
		"�ϳ������������ô������Щˮ�������ۼң�����Ҫ���õ���Ѫū���\n",
        }) );
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		 (: auto_smart_fight(40) :),
        }) );
    	
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/whip")->wield();
}

