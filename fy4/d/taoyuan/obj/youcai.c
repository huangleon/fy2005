inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("С�Ͳ�", ({ "you cai", "veg" }) );
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ�����̵�С�Ͳˡ�\n");
        set("unit", "��");
        set("value", 10);
        set("food_remaining", 4);
        set("food_supply", 15);
    }
    ::init_item();
}

