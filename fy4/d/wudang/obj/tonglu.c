inherit ITEM;

void create()
{
	set_name("ͭ¯", ({ "tong lu", "ͭ¯"}) );
	set_weight(5000);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("prep", "on");
	    set("unit", "ֻ");
	    set("long", "��ͭ���ɵĹ�¯��\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

