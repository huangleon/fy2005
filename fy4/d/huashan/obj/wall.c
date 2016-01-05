inherit ITEM;

void create()
{
	set_name("²ĞÇ½", ({ "wall", "²ĞÇ½" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "¶Â");
	    set("long", "Ò»Æ¬²ĞÇ½¶ÏÍß£¬ÅÔ±ßÔÓ²İÑÜÉú¡£\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

