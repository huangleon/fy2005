// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������", ({ "takon iron" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ط����Ĵ����顣\n");
				set("rigidity", 300);
                set("value", 0);

				set("weapon_material",1);
				set("material_level",47);
				set("desc_ext","��������(47)");
                set("material", "heavyiron");
        }

        ::init_hammer(10);
}
