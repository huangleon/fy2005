// by tie@fengyun

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(MAG"���ܲ�"NOR, ({ "carrot" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����죬�����ִ�ĺ��ܲ�\n");
		set("unit", "��");
		set("value", 35);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
