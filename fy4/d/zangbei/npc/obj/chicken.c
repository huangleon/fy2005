inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�缦", ({ "chicken" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ��ζ�ɿڵķ缦��\n");
		set("unit", "��");
		set("value", 4);
		set("food_remaining", 30);
		set("food_supply", 60);
	}
	::init_item();
}
