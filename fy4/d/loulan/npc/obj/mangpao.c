#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIM"������"NOR, ({"mang pao", "pao"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
                set("material", "cloth");
                set("long", "һ�仪���������ۣ������������������׺��\n");
                set("unit", "��");
                set("value", 1000);
                set("armor_prop/armor", 2);
        }
	::init_cloth();
}