// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("��Ѫɴ��", ({ "shayi" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������Ѫ��ɴ��\n");
		set("material", "cloth");
		set("value", 10);
	}
	::init_cloth();
}
