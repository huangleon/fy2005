
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("ˮ����", ({ "taozi", "peach" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "����͸��Ĵ�ˮ���ң�������Ӵ��\n");
        set("unit", "��");
        set("value", 20);
        set("food_remaining", 2);
        set("food_supply", 10);
    }
    ::init_item();
}