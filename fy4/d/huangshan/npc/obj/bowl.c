
inherit ITEM;

void create()
{
	set_name("����", ({ "bowl" }) );
	set_weight(500);
	set_max_encumbrance(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������õķ���\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
