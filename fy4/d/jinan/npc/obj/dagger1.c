#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(WHT"�������"NOR, ({ "ivory dagger","dagger" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���񹤾�ϸ�������̽���\n");
   				set("no_stack",1);
				set("no_drop",1);
             set("value", 0);
                set("material", "ivory");
        }
        ::init_dagger(67);
}
