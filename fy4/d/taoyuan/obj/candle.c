inherit ITEM;

void create()
{
    set_name("����", ({ "candle" , "����"}) );
    set_weight(1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ������һ�������\n");
        set("value", 100);
    }
    ::init_item();
}

