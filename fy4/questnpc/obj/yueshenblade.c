//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
    set_name(YEL "�¹⵶" NOR, ({ "moonblade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��խխ�Ķ̵����·����¹�һ�㡣\n");
		set("value", 1000);
		set("material", "steel");
		set("for_yueshen",1);
	}
    ::init_blade(30);
}
