inherit ITEM;

void create()
{
	set_name("�Ű�", ({ "�Ű�", "door" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ��������Ű塣\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

