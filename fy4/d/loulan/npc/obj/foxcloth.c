#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIW"��Ƥ��"NOR, ({"foxfur"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
                set("material", "cloth");
                set("long", "һ���ú�Ƥ���ɵĴ����\n");
                set("unit", "��");
                set("value", 1000);
                set("armor_prop/armor", 10);
        }
	::init_cloth();
}