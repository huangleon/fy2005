// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("����ɴ��", ({ "shayi" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ò����ٱ���͸�ò�����͸�Ĳ���ɴ��\n");
		set("material", "cloth");
		set("value", 1);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
