#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name("�ڿ�", ({ "pant" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ���Һ�ɫ�Ĵ���á�\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
