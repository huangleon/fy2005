inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("��������", ({ "chi yang" }) );
        set("gender", "����");
        set("age", 65);
        set("long","һ����ɫ��죬��ĸߴ�ĵ��ˡ�\n");
        
      	set("chat_chance", 1);
		set("chat_msg", ({
	        "��������Ц�������Ǵ������������������������һ�������������\n",
		}) );
	  
        set("attitude", "friendly");
        set("title",HIW"�䵱"NOR);
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","wudang");
        set("combat_exp", 4400000); 
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		     	(: auto_smart_fight(70) :),
     	}) ); 		

		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","taiji-sword",1);
        setup();
        carry_object("/obj/weapon/sword")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

 
