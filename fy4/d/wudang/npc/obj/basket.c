inherit ITEM;

void create()
{
	set_name("���", ({ "basket"}) );
	set_weight(1000);
	set_max_encumbrance(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ�����Ŀ�\n");
	    set("value", 150);
	}
	::init_item();
}

int is_container() { return 1; }

