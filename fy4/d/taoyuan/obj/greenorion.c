inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("С��", ({ "xiao cong", "" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ��ˮ�����С�С�\n");
        set("unit", "��");
        set("value", 10);
        set("food_remaining", 2);
        set("food_supply", 15);
    }
    ::init_item();
}

