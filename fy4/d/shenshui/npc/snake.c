#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
        set_name("ˮͰ���ϸ�Ĵ���", ({ "sea snake","snake" }) );
        set("race", "����");
        set("age", 4);
        set("long", "һ��ȫ���ںڣ������ڰ�ˮͰ���ϸ�Ĵ�����\n");
        set("attitude", "aggressive");
     	
		set("str",30);
        set_skill("dodge", 100);
        
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("combat_exp", 500000);
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        tell_object(ob, HIR+"\n\n"+name()+"�������ȫ��ʹ��һ�գ���ֻ���������꣢һ��������\n\n" +NOR);
                ob->receive_wound("kee",100,this_object());
}


void unconcious()
{
		::die();
}
