#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("��������", ({ "amulet" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "��");
		set("long", "һ�������Ĺ�׹��\n");
		set("armor_prop/strength",3);
		set("armor_prop/constitution",3);
		set("value",10000);
	}
	::init_neck();
}

