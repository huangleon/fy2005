inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "pearl" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��Բ��˳������顣\n");
		set("unit", "��");
		set("value", 10000);
		set("food_remaining", 1);
		set("food_supply", 60);
//		set("desc_ext","����ʳ��(eat)");
	}
	::init_item();
}
