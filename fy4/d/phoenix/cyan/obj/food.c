#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"����ǽ"NOR, ({ "tasty food","food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ζ�ޱȵķ���ǽ��\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
	::init_item();
}
