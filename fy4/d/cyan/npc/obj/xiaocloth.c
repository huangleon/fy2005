#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"����ȹ"NOR, ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ɫ��˿��ϸϸ֯�͵ļ��س�ȹ��\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value", 4000);
	}
	::init_cloth();
}
