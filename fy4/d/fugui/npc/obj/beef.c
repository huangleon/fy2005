inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("��ţ��", ({ "beef"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ոճ����Ľ�ţ�⣬��ֱð����\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 10);
		set("food_supply", 100);
		set("material", "food");
	}
	::init_item();
}
