
inherit ITEM;

void create()
{
    set_name("�Ӳ�", ({ "grass" , "�Ӳ�"}) );
	set_weight(5000);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "Ƭ");
		set("prep", "under");
        set("long", "һƬ��ǿ����������ʯ�ϵ��Ӳ�..\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


