
inherit ITEM;

void create()
{
	set_name("һƷ�����", ({ "tree" , "һƷ�����"}) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����������ʷ���Ӿ�Զ������\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
