//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("����������", ({ "cotton shirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ɫ�Ĳ��£������ϻ����Ż�����\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
