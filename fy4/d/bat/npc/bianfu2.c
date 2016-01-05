#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
        set_name("�߲�����", ({ "colorful bat","bat" }) );
        set("race", "����");
        
        set("age", 4);
        set("long", "һֻ�������߲ʵ�����\n");

        set("attitude", "aggressive");
        set_skill("dodge", 350+random(300));
        
        set("combat_exp", 800000+random(2000000));
		set("bellicosity", 3000 );
		set("agi", 15 );
        set("arrive_msg", "һ������طɹ���");
        set("leave_msg", "һ������طɿ���");
        
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
		tell_object(ob,"�߲������͵س�������һ��ҧ����Ĳ����ϣ������һ���ʹ��������\n");
        ob->apply_condition("qicaibat",this_player()->query_condition("qicaibat")+ random(3)+20);
        return;
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

