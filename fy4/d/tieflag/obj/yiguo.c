inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("���", ({ "yiguo"}) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
        set("unit", "��");
        set("long", "һ�����δ������������ӡ�\n");
        set("value", 1);
    set("food_remaining", 1);
    set("food_supply", 16);
    }
    ::init_item();
}  
