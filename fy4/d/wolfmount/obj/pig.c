inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "fried pig","pig" }) );
	set_weight(950);
	if( clonep() )
	set_default_object(__FILE__);
	else 
	{
		set("long", "һֻ���ý�ƵĴ�ƤС����\n");
		set("unit", "ֻ");
		set("value", 6000);
		set("food_remaining", 20);
		set("food_supply", 40);
		set("material", "meat");
	}
  ::init_item();
}
