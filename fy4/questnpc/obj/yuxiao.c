#include <weapon.h>
#include <ansi.h>
//inherit ITEM;
inherit DAGGER;
void create()
{
        set_name( HIG"����"NOR , ({"yuxiao"}) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("value", 100000);
                set("material", "jade");
				set("long",

"һ���ö���ǧ���������ɵ�������\n"
);
                set("wield_msg", "$N��$n����������Ϊ������\n");
        }
        init_dagger(70);
        setup();
}
