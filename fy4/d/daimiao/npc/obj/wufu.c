#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIW"������"NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","һ��ѩ�׵ĳ��ۣ���Ե��������ë��\n");
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	::init_cloth();
}
