// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("ÖıÌú¿é", ({ "zhukuai" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("long", "Ò»¿é³ÁÖØ·¢ÁÁµÄÖıÌú¡£\n");
				set("rigidity", 300);
                set("value", 40000);

				set("weapon_material",1);
				set("material_level",26);
				set("desc_ext","¼ÀÁ¶ÎäÆ÷(26)");

                set("material", "heavyiron");
        }

        ::init_hammer(10);
}
