// TIE @ FY3

inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("�������Ϲ�", ({ "pumpkin" }) );
    set_weight(800);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ��ԲԲ�ģ�Ӳ���ĳ������Ϲϣ�\n");
        set("unit", "��");
        set("value", 15);
		set("food_remaining", 100);
		set("food_supply", 100);
    }
    ::init_item();
}
