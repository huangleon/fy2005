#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        string *name = ({"��ע","����","����","��������","���","����","����","�׵�",
"����","����","��ͷ","����","����","����","����","���",
"����","���","����","�빸","����","��ʤ","����","��ʤ",
"�Ծ�","����","����","�չ�","�չ�","�ǻ�","����","�ƻ�",});
        set_name(name[random(sizeof(name))]+"����", ({"shaolin monk","monk"}) );

    	set("title","������ �޺�");
    	set("long", "����һ������޺�֮һ��\n");

	set("age",40);
	set("combat_exp", 4300000);
	set("class","shaolin");        	
	set("attitude","aggressive");
	
	set("pursuer",1);
	set("maze","shaolin");
	
	
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		(: auto_smart_fight(20) :),
        }) ); 		

	switch (random(3)) {
		case 0:	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","shadowsteps",1); 	break;
		case 1: auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","shadowsteps+dragon",1);	break;
		default: auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","shadowsteps+lingxi",1);	break;
	}
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "�����޺���",
    						"long": "�����޺���ɮ�¡�\n",
    						 ]))->wear();  

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