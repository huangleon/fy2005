#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(CYN"����֮��"NOR, ({ "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "steel");
		set("long", "һ��û�н��ɵĽ�������ܱ������ᣬȴ�൱�ͣ���������������⡣\n");
	}
	::init_sword(20);
}
