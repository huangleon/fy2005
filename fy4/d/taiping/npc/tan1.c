#include <ansi.h>
#include <command.h>
inherit SMART_NPC;
inherit __DIR__"timeshift";

int red_stone();
void throw_away(object ob);

void create()
{

	set_name("̷����",({"tan tianlong","tan"}));
    	set("title",YEL"̷�������� �ϴ�"NOR);
    	set("long", "
̷�������쵱Ȼ��̷��Ҳ�����ǲ����Ǳ���̷�ȵĵ�ϵ�����������Լ�Ҫ��ô˵��
��û���˸һ��ɣ�Ҳû���˷��ϡ�ƴ��ʮ�������������˴�С���ٶ��ԡѪ��ս��
��̷�������족ȷʵ���ڽ���������վס�˽ţ����Ƶ����ǵ��ˣ�������ѱ���
��һ��������\n");

	set("age",40);
	set("combat_exp", 6500000);
	set("class","swordsman");        	
	set("attitude","friendly");
	set("group","tan");
	
	set("reward_npc",5);
		
	set("day_room","/d/taiping/house1");
	set("dinner_room","/d/taiping/laodian");
	set("shift/dinner_leave","$Nһ��������һ������˵��������쵭���������ˣ���\n");
	set("shift/dinner_arrive","$N�߹���һ�����ӣ����죬�ϲˡ���\n");
	set("shift/after_dinner","$NĨ��Ĩ�죬����������ű����߳����š�\n");
	set("shift/back_dinner","$N�ε��ε����˹�����\n");
	
	set("death_msg",CYN"\n$N˵���϶�������Ϊ�ұ���ġ������������� \n"NOR);		
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	20: 	(: red_stone() :),
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps",1);
		
	setup();
	carry_object(__DIR__"obj/hat")->wear();
	carry_object(__DIR__"obj/lan_cloth1")->wear();

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
	
	my_position=file_name(environment(this_object()));
	if(my_position==this_object()->query("day_room")) {
		command("say ˭��������ģ�����ȥ��");
		call_out("throw_away",10,ob);
	}
	remove_call_out("shifting");
	call_out("shifting", 1, this_object());

}

void throw_away(object ob) {
	if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
	this_object()->kill_ob(ob);
	kill_ob(this_object());
}

int red_stone() {
	object me,ob, stone;
	me=this_player();
	ob=this_object();
	if (file_name(environment(ob))!= AREA_TAIPING"laodian") return 1;
	message_vision(WHT"\n$NͻȻŭ�������������˫�������߳������Ѳ������ڵ�̷�ȣ�����ȴԶ
��̷�ȸ����������ݺὭ���ĳ���������\n"NOR, ob);
        message_vision(WHT"˭֪$N���Ӹ����𣬾��������꣬�ꡱ�����죬����һ���Һ���\n"NOR,ob);
        message_vision(WHT"$N����ȥʱ�������ȵ�ϥ�ǹؽڴ������ѡ�\n"NOR,ob);
        stone=new(AREA_TAIPING"npc/obj/redstone");
        if (stone) stone->move(ob);
        die();
        return 1;
}	

