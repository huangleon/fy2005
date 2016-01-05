#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
        set_name("�����", ({ "bad frog","frog" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�綾�ĵ����\n");
		set("attitude", "aggressive");
		set("bellicosity", 300 );
	       
        set_skill("dodge", 200);
        set("combat_exp", 100000+random(999999));
	
	
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if(sizeof(enemy) ) 
        	ob = enemy[random(sizeof(enemy))];

        tell_object(ob,WHT"���������һ�飬�����Ѿ�����ղ�����ˡ�\n"NOR);
		ob->receive_wound("kee",40,this_object());
        ob->apply_condition("unknown",this_player()->query_condition("unknown") + random(3)+3);
}


