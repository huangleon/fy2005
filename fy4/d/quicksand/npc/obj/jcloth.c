
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�׳���", ({ "cloth" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ��ѩ�׵ĳ�����������Ķ���֯�ɡ�\n");
		set("material", "cloth");
		set("value",1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
