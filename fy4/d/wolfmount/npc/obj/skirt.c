#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIG"��ɴ��ȹ"NOR, ({ "long skirt", "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "һ���������ʵ�ɴȹ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}
