#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;

void create()
{

	set_name("�һ�����",({"taohua","niangzi","taohua niangzi"}));
    set("title",YEL"÷��������"NOR);
	set("long", "�����������ϵı��飬�������۾������ֳ��Թ��֮ɫ����������˭
���ܿ��ó��ġ���\n");
	set("gender","Ů��");
	set("age",39);
	set("combat_exp", 7500000);
	set("attitude", "aggressive");
	
	set("reward_npc",8);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	   	(: auto_smart_fight(50) :),    
     }) );
	
	auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object another;
	message("vision",name() + "̾�˿������ֳ���һ�����ϸɿݵ����ᡣ\n", environment(),
		this_object() );
	another = new(__DIR__"liaoyin");
	another->move(environment(this_object()));
	destruct(this_object());
}

