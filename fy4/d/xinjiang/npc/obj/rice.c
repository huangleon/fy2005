// rice.c
inherit COMBINED_ITEM;
inherit F_FOOD;
void create()
{
	set_name("ץ��", ({ "zhua fan","rice" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ץ������������һ�ڣ�\n");
		set("unit", "Щ");
		set("base_unit", "��");
                set("base_weight", 40);
                set("base_value", 100);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	set_amount(1);
}
