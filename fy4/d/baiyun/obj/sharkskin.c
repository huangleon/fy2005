#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("����Ƥ", ({ "shark skin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
	set("no_stack",1);
		set("for_create_cloth",1);
		set("armor_prop/armor", 5);
		set("long","һ������ޱȵ�����Ƥ��\n");
		set("max_enchant",7);
		set("base_armor",50);
		set("value",0);
	}
	::init_cloth();
}
