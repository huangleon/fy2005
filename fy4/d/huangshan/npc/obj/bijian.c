// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIG"�̽�"NOR, ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѵ���ɫ�Ľ���������ϸ�ֳ���\n");
		set("value", 400);
		set("material", "steel");
	}
	::init_sword(15);
}
