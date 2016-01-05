#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("������", ({ "butterfly" }) );
        set("race", "����");
        set("age", 1);
        set("long", "һֻ˶��ķ�ɫ����������ɫ�����ƺ�������������Һ����\n");
        
        set("target_name","������");
            	
		set("maze","taoyuan");
	  	
    	set("chat_chance",1);
    	set("chat_msg",({
			"��ɫ������Ȼ�������������һ������������衣\n",
    	}) );  

        set("combat_exp",200000);
        set_skill("dodge", 300);
        set_temp("apply/attack",150);
        
        setup();
}


void die(){
	
	object *enemy;
	int n;
	
	enemy = this_object()->query_enemy();
	n = sizeof (enemy);
	message_vision(HIG"\n�������˵�һ��������һ������������\n"NOR,this_object());
	if (n)
	while (n--)  
		if (enemy[n]) {
			enemy[n]->receive_damage("sen",enemy[n]->query("max_kee")/20,this_object());
			COMBAT_D->report_status(enemy[n]);
		}
	::die();	
}