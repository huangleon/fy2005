// TIE@fy3
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name(HIY"���Ӽ�"NOR, ({ "suozijia", "jia" }) );
	set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "gold");
		set("value", 100000);
		set("armor_prop/armor", 80);
		set("armor_prop/dodge", -40);
	}
   ::init_cloth();
}
