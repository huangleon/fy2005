#include <armor.h>
inherit MASK;


void create() {
	set_name("«έ", ({ "luwei", "«έ" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���пյ�«έ��\n");
		set("value", 0);
		set("wear_msg", "$N��«έ��һͷ�������С�\n");
		set("unequip_msg", "$N������ȡ��«έ��\n");
		set("armor_prop/use_under_water", 30);
		set("armor_prop/long", ({"�������Ϻ���һ��������«έ�����ǲ��˸��С�\n"}) );
	}
	::init_mask();
}