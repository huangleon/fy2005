#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name(BLK"���몲���"NOR, ({ "tibetan robe", "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "leather");
		set("value", 400);
		set("armor_prop/armor", 10);
		set("long","һ�����شֱ���������ɳ�͹��ĺ��몲��ۡ�\n");
	}
	::init_cloth();
}
