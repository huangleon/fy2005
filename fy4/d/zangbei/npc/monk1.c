#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("����µ�����",({"chonggu lama","lama"}));
	set("long", "���ǳ���»�����Ժ�����\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 4500000);
	
	
   	set("inquiry", ([
		"ת��":		"����ǧת���������ã�\n", 
		"˾������": "����λ��ͣ�û�������˰���\n",
   	]));
   	
	set("chat_chance", 1);
        set("chat_msg", ({
		
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("wang",300,180,0,"/obj/weapon/","fighter_w","liuxing-hammer",1);
	
	setup();
	carry_object(__DIR__"obj/lamacloth")->wear();
	carry_object("/obj/weapon/hammer",([	"name": "����N",
    						"long": "�̶̵İ���, �Ͻ�һ���F�T�ĈA��, �����@�ˡ�\n",
    						"weight": 20000,
    						"value" : 1,
    						 ]))->wield();    
}
