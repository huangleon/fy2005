inherit ITEM;

void create()
{
        set_name("����", ({ "big tree","tree"}) );
        set_weight(100);
	set("no_get", 1);
        set("no_shown", 1);
        set_max_encumbrance(80000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ï�ܵĴ�����\n");
        }
	::init_item();
}

int is_container() { return 1; }

