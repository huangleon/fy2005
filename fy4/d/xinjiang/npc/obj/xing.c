// copyright c apstone, inc.

inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("�⳵����", ({ "xing" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�½��ز������ⷢ��ɫ��\n");
		set("unit", "��");
		set("value", 55);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
	::init_item();
}
