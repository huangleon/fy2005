//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit HEAD;
void create()
{
	set_name("ά�����ñ", ({ "cotton hat" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��������ɫ���ֺܺÿ���ñ�ӡ�\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_head();
}
