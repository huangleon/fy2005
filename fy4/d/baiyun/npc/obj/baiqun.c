#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
    set_name(HIW"��ȹ"NOR, ({ "baiqun" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
        set("long", "һ�����İ�ɫ��ȹ��\n");
		set("material", "cloth");
		set("value", 20);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
