inherit ITEM;

void create()
{
        set_name("�ݴ�", ({ "grass" , "�ݴ�"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("long", "������é�ݸ�����·�档\n");
                set("value", 1);
        }
    ::init_item();
}

int is_container() { return 1; }


