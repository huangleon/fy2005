inherit ITEM;

void create()
{
	set_name("С����", ({ "nest", "����" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ����С��֦��ɵ����ѣ������������޵���ë��\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

