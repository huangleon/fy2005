// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���õķۺ첼��", ({ "pink cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ۺ�ɫ�Ĳ�����մ���˰���ɫ��Ѫ����\n");
		set("unit", "��");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}

