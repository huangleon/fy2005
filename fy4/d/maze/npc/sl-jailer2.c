#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void throw_away(object ob);

void create()
{
	set_name("��������",({"fuhu monk","monk"}));
    	set("title","������ �޺�");
    	set("long", "����һ������޺�֮��ϯ����\n");

	set("age",60);
	set("combat_exp", 5500000);
	set("attitude","friendly");
	set("group","shaolin");
	
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) ); 		

	auto_npc_setup("wang",200,200,1,"/obj/weapon/","fighter_w","fumostaff",1);
		
	setup();
    	carry_object(__DIR__"obj/sl-key");
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
	message_vision(YEL"�������ߺ��Ƴ��˸�ŵ����ʩ�������������������ʥ�أ��ٲ����룬
ˡ�������������ˣ� \n\n"NOR,ob);
	call_out("throw_away",10,ob);
	
}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	message_vision(YEL"�����������һ���������ֿ�ɽ��������û��������������Ұ�� \n"NOR,ob);
	this_object()->kill_ob(ob);
	ob->kill_ob(this_object());
}

