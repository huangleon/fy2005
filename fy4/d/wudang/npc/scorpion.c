#include <ansi.h>
inherit NPC;

int bite();

void create()
{
	set_name("�߲�Ы��", ({ "scorpion" }) );
        set("race", "����");
        set("subrace","����");
        set("attitude", "aggressive");
        set("age", 1);
        set("long", "һֻ���糤�Ĵ�Ы�ӣ�ģ��ʮ���׶�\n");

         
    	set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	    	     
		set("combat_exp",100000);
        set_skill("dodge", 200);
        set_temp("apply/attack",100);
        setup();
}



int bite(){
	object ob,*enemy, target;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
	if (!random(3)) target = enemy[random(sizeof(enemy))];
	if (target) {
		message_vision(HIM"�߲�Ы�ӽ�β��һ˦��ž��һ�������㡣\n"NOR,target);
		tell_object(target,HIB"�㰥��һ�����Ȳ���������һ���˺ۡ�\n"NOR);
		target->receive_wound("kee",target->query("max_kee")/20,ob);
		COMBAT_D->report_status(target);
		ob->start_busy(1);
	}
	return 1;
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
	message("vision","�߲�Ы��ϤϤ��������������ѡ�\n", environment(),this_object() );
	destruct(this_object());
}
