#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("��������",({"tianmei"}));
    	set("title",YEL"ħ��"NOR);
    	set("long", "
����������ħ��ǰ���������������˵�Ů��������ǰ�����������࣬������
��ʨһ���ѽ̳��ߣ��������ġ����������л�����й�һ����Ե��������
Ů��лС��\n");

		set("gender","Ů��");
	set("age",50);
	set("combat_exp", 8500000);
	set("attitude","friendly");
	
	set("reward_npc",10);
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) ); 		

	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","necromancy",1);
		
	setup();
	carry_object("obj/armor/surcoat",([	"name": "���ᶷ��",
    						"long": "һ�����ᶷ��\n",
    						"value": 2,
    						 ]))->wear();
    	carry_object("obj/armor/cloth")->wear();
}
