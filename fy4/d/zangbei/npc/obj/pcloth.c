#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name("ԡ��", ({ "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 5);
		set("long","һ����͸����ɴ�¡�\n");
	}
	::init_cloth();
}
