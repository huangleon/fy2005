// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ź", ({ "nenou" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ϴ�øɸɾ�������ź\n");
		set("unit", "��");
		set("value", 1000);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
}
