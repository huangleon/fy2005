#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIB"��ħ����"NOR, ({ "magicial robe","robe" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������â����ħ���ۡ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value", 200);
	}
	::init_cloth();
}
