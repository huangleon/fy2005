// bag.c

inherit ITEM;

void create()
{
	set_name("����԰Ͱ", ({ "steel tube" }) );
	set_weight(50);
	set_max_encumbrance(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������԰Ͱ\n");
		set("value", 100);
	}
}

int is_container() { return 1; }
