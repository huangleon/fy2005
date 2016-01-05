#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("���ϵ�����",({"bandit"}));
	set("long", "����һ��ר�Ŵ�����̵���������֪Ϊʲô�������\n");
	
	set("age",30+random(20));
	set("attitude", "aggressive");
	
	set("combat_exp", 1000000);
		
	set("chat_chance", 1);
    set("chat_msg", ({
        }) );
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
     }) );
	
	auto_npc_setup("guardian",120,100,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
	carry_object(__DIR__"obj/oldcloth")->wear();
	carry_object(__DIR__"obj/niren");
	carry_object(__DIR__"obj/picture");
	
}


void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() ) return;
	message_vision(CYN"$N�ȵ���ʲô�ˣ���\n"NOR,this_object());
}



void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
 	if (me)
        if(!me->query_temp("eren/bandit_2") 
        	&& me->query_temp("eren/bandit_1"))
        {
                me->set_temp("eren/bandit_2",1);
        }
        ::die();
}
	