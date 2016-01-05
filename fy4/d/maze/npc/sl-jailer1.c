#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

		set_name("��������",({"xianglong monk","monk"}));
    	set("title","������ �޺�");
    	set("long", "����һ������޺�֮�ס�\n");

		set("age",40);
		set("combat_exp", 5100000);
		set("attitude","friendly");
		set("group","shaolin");
		
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","shangren",1);
		
		setup();
//	carry_object(AREA_MAZE"obj/jade_2");
    	carry_object("/obj/armor/cloth",([	"name": "�����޺���",
					"long": "�����޺���ɮ�¡�\n",
					 ]))->wear();  

}

void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object *inv;
	string my_position;
	if( !ob || environment(ob) != environment()) return;
	message_vision(YEL"�����������һ���������ֿ�ɽ��������û��������������Ұ�� \n\n"NOR,ob);
	call_out("throw_away",10,ob);
	
}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	this_object()->kill_ob(ob);
	ob->kill_ob(this_object());
}

