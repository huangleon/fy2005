inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("���ͱ�", ({ "bing" }) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ�������硢�����ڵĴ��ͱ�\n");
        set("unit", "��");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 60);
    }
    ::init_item();
}

