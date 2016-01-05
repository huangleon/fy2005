// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("ÎÚÌú¿é", ({ "tiekuai" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("long", "Ò»¿é³ÁÖØµÄºÚÌú¿é¡£\n");
				set("rigidity", 500);
                set("value", 10000);
                set("material", "iron");

			set("weapon_material",1);
			set("material_level",12);
			set("desc_ext","¼ÀÁ¶ÎäÆ÷(12)");

        }

        ::init_hammer(10);
}
