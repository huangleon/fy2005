#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create() {
	set_name(HIR"��춷��"NOR, ({ "red cloak", "cloak" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "leather");
		set("value", 400);
		set("armor_prop/armor", 10);
		set("long","һ���ʺ�ģ�Ů���Ӵ��Ķ���\n");
	}
	::init_surcoat();
}
