#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name("����", ({ "cloth" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("long","һ������ɫ�İ�ɵĲ��£����滹�м�������\n");
	}
	::init_cloth();
}
