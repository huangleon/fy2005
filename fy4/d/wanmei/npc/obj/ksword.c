#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIG"���´�"NOR, ({ "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѽ�����Ľ���\n");
		set("value", 100);
		set("material", "steel");
		set("rigidity", 4000);
	}
	::init_sword(10);
}
