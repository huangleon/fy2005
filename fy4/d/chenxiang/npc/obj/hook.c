#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("����", ({ "hook" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻڳ����������������ƺ������Ż��أ�");
                set("value", 300);
                set("material", "steel");
        }
        ::init_sword(20);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(damage_bonus)>300) return;
        if (random(me->query_skill("sword")) > victim->query_skill("dodge"))
        	victim->receive_wound("kee",damage_bonus/5);
        	return this_object()->name()+ HIB "��ͻȻ���һ�Ժںڵ�ţëϸ�룡\n"NOR;
}
