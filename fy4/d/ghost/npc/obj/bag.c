inherit ITEM;

void create()
{
        set_name("Ƥ��", ({ "bag"}) );
        set_weight(100);
        set_max_encumbrance(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ۺ�ɫ��Ƥ�ҡ�\n");
                set("value", 0);
        }
	::init_item();
}

int is_container() { return 1; }

