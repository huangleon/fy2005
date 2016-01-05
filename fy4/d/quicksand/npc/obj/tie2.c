// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("ÊìÌú¿é", ({ "shoukuai" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("long", "Ò»¿é³ÁÖØµÄÊìÌú¿é¡£\n");
				set("rigidity", 400);
                set("for_create_weapon",1);
                set("value", 20000);
                set("material", "copper");

				set("weapon_material",1);
				set("material_level",19);

				set("desc_ext","¼ÀÁ¶ÎäÆ÷(19)");
        }

        ::init_hammer(15);
}
