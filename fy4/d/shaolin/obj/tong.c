inherit ITEM;

void create()
{
        set_name("ͭ��", ({ "tong bei", "bei", "ͭ��"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "behind");
                set("unit", "��");
                set("long", "����ͭ���ձ���\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

