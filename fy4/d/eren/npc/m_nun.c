#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;

void create()
{

	set_name("ɨ�ص�����Ů��",({"middle aged nun","nun"}));
	set("long", "һ������ʮ���Ů�ᣬ������ǰ��ɨ��Ҷ���������������¶�����֮ɫ��\n");
	set("age",39);
	set("gender","Ů��");
	set("combat_exp", 3500000);
	set("attitude", "friendly");
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
	auto_npc_setup("nun",200,160,0,"/obj/weapon/","magician","necromancy",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/necklace",([	"name": "��ľ����",
    						"long": "һ����ľ�������ɵľ�����\n",
    						"value": 1,
    						 ]))->wear();  
}


