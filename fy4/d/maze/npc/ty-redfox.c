#include <ansi.h>
inherit MAZE_NPC;
int bite();

void create()
{
        set_name(HIR"��ë����"NOR, ({ "red fox","fox" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", HIR"һֻ����ĺ�ë���꣬��ɫ��Ƥë��ͬ��һ��ȼ���ţ�һ˫��ɫ�������׹���¶����\n"NOR);
        
		set("target_name","��ë����");
		set("pursuer",1);
		if (!random(5))	set("attitude", "aggressive");
        set("group","fox");
        set("maze","taoyuan");
            	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		RED"��ë������¶Ѫ�⣬ֱ�����㡣\n"NOR,
    	}) );  
        
		set("combat_exp",350000);
        set_skill("dodge", 400);
        set_skill("move",400);
        set_temp("apply/attack",200);
        setup();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
	if(arg == "red fox"){
		write("һֻ����ĺ�ë���꣬��ɫ��Ƥë��ͬ��һ��ȼ���ţ�һ˫��ɫ�������׹���¶��\n");
		write("���������ų������졣\n");
		write("�����Ĳ��ֲ��ݣ��书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
		write("�����������������۷�״̬��\n");
		return 1;
	}
	return 0;
}

int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(name()+RED"�͵ز���һ������������$Nֻ����ǰһƬ��⣬Ѫ��է�֡���\n"NOR,target);
		tell_object(target,HIR"�㾱��һ���ʹ��\n"NOR);
		target->receive_damage("sen",target->query("max_sen")/20,ob);
		COMBAT_D->report_status(target);
		this_object()->start_busy(1);
	}
	return 1;
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