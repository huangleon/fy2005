// TIE @ FY3

inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("����ĺ�ɫ��ʵ", ({ "red fruit" }) );
    set_weight(8000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ����ɫ�Ĺ��ӣ�ɢ���ŵ���������\n");
        set("unit", "��");
        set("value", 1);
        set("food_remaining", 3);
        set("food_supply", 300);
    }
    ::init_item();
}


