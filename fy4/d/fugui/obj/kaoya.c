// kaoya.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��Ѽ", ({ "kaoya" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ������Ŀ�Ѽ��\n");
		set("unit", "ֻ");
		set("value", 1000);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
	::init_item();
}
