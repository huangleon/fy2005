// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ëȹ", ({ "skirt", "white skirt" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ѩ�׵���ëȹ������������һ����Ů�����㡣\n");
		set("unit", "��");
		set("value", 6);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("female_only", 1);
	}
	::init_cloth();
}

