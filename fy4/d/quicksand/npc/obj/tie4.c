// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name("������", ({ "shengkuai" }) );
    set_weight(50000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        	set("unit", "��");
        	set("long", "һ����ط�����������\n");
    		set("rigidity", 200);
        	set("value", 80000);
        	set("material", "heavyiron");
			set("weapon_material",1);
			set("material_level",33);
			set("desc_ext","��������(33)");
    }
    
    ::init_hammer(15);
}
