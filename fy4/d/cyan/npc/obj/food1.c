#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(CYN"����"NOR, ({ "dumpling"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ӳ�����ڰ��ӡ�\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	::init_item();
}
