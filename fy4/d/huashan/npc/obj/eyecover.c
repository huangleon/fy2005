#include <ansi.h>
#include <armor.h>

inherit MASK;

void create()
{
        set_name( YEL"����"NOR, ({ "eye cover", "cover" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        ::init_mask();
}
