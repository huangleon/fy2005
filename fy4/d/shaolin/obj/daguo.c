inherit ITEM;

void create()
{
        set_name("���", ({ "giant wok" }) );
        set_weight(500000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����������Ĵ����\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

