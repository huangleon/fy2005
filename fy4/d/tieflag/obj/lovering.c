// tblade.c
#include <ansi.h> 
#include <weapon.h> 
inherit HAMMER;
void create()
{
        set_name(WHT"���黷"NOR, ({ "lover ring","ring" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ˫���������������\n
���������һ�ֺޣ���ޣ�\n"
);
                set("value", 1000);
                set("material", "silver");
                set("rigidity", 10000); 
        }
        ::init_hammer(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        return HIR "$N�����б������������\n"NOR;
}
