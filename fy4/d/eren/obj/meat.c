inherit ITEM;
inherit F_FOOD;

void create()
{
	int i;
	set_name("������", ({ "meat" }) );
    	set_weight(500);
    if( clonep() )
	    set_default_object(__FILE__);
    else {
        set("long", "һ�������磬�͹��ĺ����⡣\n");
        set("unit", "��");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 10);
    }
    ::init_item();
}

