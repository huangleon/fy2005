// rice.c
inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("���ܹ�", ({ "hami gua" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ִ�Ĺ��ܹϣ�������������ô�㣡\n");
		set("unit", "Щ");
		set("base_unit", "��");
                set("base_weight", 40);
                set("base_value", 10);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
	set_amount(1);
}
