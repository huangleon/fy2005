#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("��ɫ������", ({ "darkcloth"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "vine");
		set("long", "һ����ɫ�����¿���\n");
		set("value", 1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
