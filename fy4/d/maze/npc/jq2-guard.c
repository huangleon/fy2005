#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("��������", ({ "guard"}) );
        set("gender", "����" );
        set("title",YEL"��Ǯ��  "NOR);
        set("age", 32);
        set("long", "���ؽ�Ǯ���ε����������������׼���֮ͽ��\n");
        set("maze","jq2");
        set("combat_exp", 2500000);
        set("attitude", "aggressive");
        set("pursuer",1);
              
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"�ȵ���ʲô�˸�˽�����Σ�\n",
        }) );
		
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(15) :),    
        }) );
	
		auto_npc_setup("liaoyin",180,170,1,"/obj/weapon/","fighter_w","smallguy",1);
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}