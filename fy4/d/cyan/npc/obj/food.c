inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ç¬Á¸", ({ "food"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÓ²°ð°ðµÄÇ¬Á¸¡£\n");
		set("unit", "¿é");
		set("value", 5);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
