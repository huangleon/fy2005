// venomsnake.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "venomsnake", "snake" }) );
        set("long",     "һ���������ŵĶ�������������ض����㡣\n");

        set("race", "����");
        set("age", 3);
		set("combat_exp",20000);
        
        set_temp("apply/attack", 10);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10);
       
        setup();
}

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 2 ) {
                ob->apply_condition("snake_poison", 3);
                tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n"NOR );
        }
}
