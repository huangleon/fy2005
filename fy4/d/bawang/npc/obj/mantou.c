// mantou.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����ͷ", ({ "mantou" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������������ڵĴ���ͷ��\n");
		set("unit", "��");
        set("value", 800);
		set("food_remaining", 9);
		set("food_supply", 60);
	}
	::init_item();
}
