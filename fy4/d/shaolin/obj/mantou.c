// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ", ({ "mantou" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ӳ�Ĵ���ͷ\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
