#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("��ȹ��", ({ "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��Ư��������ȹ��");
		set("female_only",1);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
