//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("��ɴ��", ({ "black robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǽ���ɫ��ɴ�ۣ�������һ�ɺܶ��ĵ���ζ��\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
