#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(CYN"��米�ȹ"NOR, ({ "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1400);
                set("material", "cloth");
		set("armor_prop/armor", 2);
                set("wear_msg", "$N��$n�ó�ϵ�����ϡ�\n");
                set("female_only",1);
        }
	::init_cloth();
}
