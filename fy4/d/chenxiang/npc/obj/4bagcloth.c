// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�Ĵ�����", ({ "4bag-cloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 2);
		set("value",400);
        }
        ::init_cloth();
}
