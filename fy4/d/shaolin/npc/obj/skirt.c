// skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ȹ", ({ "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "H���Ǽ�ƽ��Ů�ӵ���ȹ��\n");
		set("unit", "��");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	::init_cloth();
}

