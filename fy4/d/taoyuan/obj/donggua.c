inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("����", ({ "dong gua", "veg" }) );
    set_weight(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ�����Ű�˪�Ķ��ϡ�\n");
        set("unit", "��");
        set("value", 25);
        set("food_remaining", 5);
        set("food_supply", 25);
    }
    ::init_item();
}

