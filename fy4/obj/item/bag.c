// bag.c

inherit ITEM;

void create()
{
	set_name("����", ({ "bag" }) );
	set_weight(500);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("prep", "inside");
		set("unit", "��");
		set("long", "����һ��Ѱ���Ĳ�������������װһЩ���\n");
		set("value", 100);
	}
}

int is_container() { return 1; }
