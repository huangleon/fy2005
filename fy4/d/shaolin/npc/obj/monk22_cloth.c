// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
//        string *order=({"�ֲ�", "�޲�", "����", "ϴ�÷��׵�",
//"�಼","�ϲ�","�ڲ�","�ײ�"});
        set_name("�޲�����ɮ��", ({ "monk clothes", "clothes"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("shaolin_cloth",1);
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",100);
	}
	::init_cloth();
}
