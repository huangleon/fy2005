#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("��β����Ƥ", ({ "hide"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "leather");
		set("long", "һ�ž�β��������Ƥ��\n");
		set("value", 200);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
