// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("����", ({ "yun cloth", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
        set("value", 10);
        set("long", "һ�����������Ʋ�ͼ���ĳ��ۡ�\n");
	}
	::init_cloth();
}
