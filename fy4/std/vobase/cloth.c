// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;
inherit F_VO;

void create()
{
	set_name("��ͨ����", ({ "cloth" }) );
	set_weight(3000);	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�����¡�\n");
		set("value",20);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}

