#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIM"��������"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}
