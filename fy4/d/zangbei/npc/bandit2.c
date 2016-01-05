#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("����",({"bandit"}));
	set("long", "����һ��ר�Ŵ�����̵�������\n");
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 1500000);
	set("group","bandit");
		
	set("chat_chance", 1);
        set("chat_msg", ({
        }) );
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("guardian",150,125,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
	carry_object(__DIR__"obj/oldcloth")->wear();
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
	
	if (ob->query("gender")=="Ů��") {
		switch (random(3)) {
			case 0: message_vision(CYN"$N����$n�е������ˣ����¸��Ŵ�ү��������ɣ�\n"NOR,this_object(),ob);
				break;
			case 1: command("rose "+ob->query("id"));
				break;
			default: command("qmarry "+ob->query("id"));
		}
		return;
	}
	else if (ob->query("combat_exp")<2500000){
		message_vision(CYN"$N�е����ٲƲ�������ʶ��ľͰѽ������£���ү����һ����·��\n"NOR,this_object());
		kill_ob(ob);
	}
	else
		command("say ��ү����ߣ���㿴���Ǻǡ�");
}


void die(){
	
	object *inv;
	int i, friend;
	
	inv = all_inventory(environment());
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]==this_object()) continue;
		if (inv[i]->query("group")=="bandit")	friend =1;
	}

	if (friend) {
		message_vision(CYN"$N���һ�������ã��������֣���ȥ���ţ��㶥�ţ�\n"NOR,this_object());
		message_vision("$Nһ���̵������汳���ܵ��ˡ�\n",this_object());
		destruct(this_object());	
		return ;
	}
	
	::die();    
}
