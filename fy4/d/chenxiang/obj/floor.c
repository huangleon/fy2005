inherit ITEM;

void create()
{
        set_name("�ذ�", ({ "stone floor", "floor", "�ذ�"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep", "on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һƬ��ɨ�ù��ɾ�����ʯ�ذ塣\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }
