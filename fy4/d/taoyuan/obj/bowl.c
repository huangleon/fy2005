inherit ITEM;

void create()
{
	set_name("��", ({ "bowl", "rice bowl", "��"}) );
    set("no_shown", 1);
	set("no_get",1);
    set_weight(500);
    set_max_encumbrance(200);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
		set("prep", "in");
        set("long", "һ���໨���룬����Χ������������øɸɾ�����\n");
        set("unit", "��");
        set("value", 20);
    }
    ::init_item();
}

int is_container() { return 1; }
