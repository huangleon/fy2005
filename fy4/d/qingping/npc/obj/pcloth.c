// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ϳ���", ({ "purple cloth", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
                set("value", 30);
                set("long", "һ������ͨͨ����ɫ���ۡ�\n");
	}
	::init_cloth();
}
