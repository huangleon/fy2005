#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("������������", ({ "leader"}) );
        set("gender", "����" );
        set("title",YEL"��Ǯ��  "NOR);
        set("age", 32);
        set("long", "���ؽ�Ǯ���ε����������������׼���֮ͽ��\n");
        set("maze","jq2");
        set("combat_exp", 3500000);
        set("attitude", "aggressive");
        set("pursuer",1);
        
        set("experience",1000);
	set("potential",150);
	set("money",500);
	set("toughness",250);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽�����Σ�\n",
        }) );
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(15) :),    
        }) );
	
	auto_npc_setup("liaoyin",200,200,1,"/obj/weapon/","fighter_w","smallguy",1);
	set_skill("perception",200);
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	switch (random(5)) {
    		case 1:	 carry_object(__DIR__"obj/jq2-herb1"); break;
    		case 2:	 carry_object(__DIR__"obj/jq2-herb2"); break;
    		case 3:	 carry_object(__DIR__"obj/jq2-herb3"); break;
    		case 4:	 carry_object(__DIR__"obj/jq2-herb4"); 
    	}	
}
