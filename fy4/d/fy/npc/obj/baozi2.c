// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ѽ�Ͱ�", ({ "yabao" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������硢�����ڵĴ���ӡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
	::init_item();
}
