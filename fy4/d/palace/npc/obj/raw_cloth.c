#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("��Ƥ", ({ "hide"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("long", "һ����Ұ��Ƥ���ɵ�����֮�\n");
		set("value", 2000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
