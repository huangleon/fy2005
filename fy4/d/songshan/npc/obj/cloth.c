// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        string *order=({"�ֲ�", "�޲�", "����", "ϴ�÷��׵�",
"�಼","�ϲ�","�ڲ�","�ײ�"});
        set_name((order[random(8)]) +"����ɮ��", ({ "monk clothes", "clothes"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
