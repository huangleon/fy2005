inherit ITEM;
inherit F_FOOD;

void create()
{
	int i;
	set_name("ºìÉÕÈâ", ({ "meat" }) );
    	set_weight(500);
    if( clonep() )
	    set_default_object(__FILE__);
    else {
        set("long", "Ò»¿éÏãÅçÅç£¬ÓÍ¹â¹âµÄºìÉÕÈâ¡£\n");
        set("unit", "¿é");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 10);
    }
    ::init_item();
}

