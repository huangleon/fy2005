inherit ITEM;

void create()
{
	set_name("Сľ��", ({ "storage" , "Сľ��", "ľ��" }) );
    set_weight(50000);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
    	set("unit", "��");
    	set("long", "Сľ�ﲻ���Ǹɾ���ˬ��\n");
        set("value", 1);
    }
    ::init_item();
}

int is_container() { return 1; }


