#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����ǽ", ({ "inesculent food","food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�͡��������������Ѿ������ķ���ǽ��\n");
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
	::init_item();
}
