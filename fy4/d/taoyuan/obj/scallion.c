inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("�л�", ({ "scallion" }) );
    set_weight(1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "�ɸɾ����Ĵл���\n");
        set("unit", "Щ");
        set("value", 5);
        set("food_remaining", 1);
        set("food_supply", 10);
    }
    ::init_item();
}

