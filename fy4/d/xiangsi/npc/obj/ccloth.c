#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ͦ����", ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ͦͦ����ɫ������\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 2000);
	}
	::init_cloth();
}
