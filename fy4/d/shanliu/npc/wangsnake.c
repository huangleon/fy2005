#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
    set_name(HIY"����"NOR, ({ "wang snake", "snake" }) );
    set("race", "����");
    set("age", 1);
    set("gender", "����");
    set("long", "һ��ȫ���ɫ��С�ߣ�����԰���ɱ��ȡ�������ߵ���˵����ҽ��������� 
��֢�� \n");
    set("attitude","peaceful");
    set("weight", 300);
    set("combat_exp", random(100000));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
    	(: use_poison :),
    }));
    setup();
}

void use_poison()
{
    object *enemy, ob;
    string msg;

    enemy = query_enemy();
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	message_vision(HIY"ֻ��һ�������𣬳���$N��\n"NOR, ob);
    tell_object(ob,HIC"��ֻ��������һ�飬һ����˳�ž�������ȫ��\n"NOR);
    ob->receive_wound("kee",50, this_object());
    ob->apply_condition("canxia", 
    	(int)this_player()->query_condition("canxia")
    	+ random(2)+1);
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
        object playsnakebeggar;
		if (playsnakebeggar = present("playsnake beggar",environment(this_object())))
        {
			message_vision("$N����һ���������$n�����в�����\n",this_object(),playsnakebeggar);
        }else
		{
			message_vision("$N����һ��,Ѹ�ٵ�������\n",this_object());
		}
        destruct(this_object());
}


void die()
{
	object sedan;
	sedan = new(__DIR__"obj/wangshedan");
	sedan->move(this_object());
	::die();
}