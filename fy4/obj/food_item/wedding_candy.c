inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ϲ��", ({ "candy"}) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ǹ��������������š�������顱�ĸ��֡�\n");
		set("unit", "��");
		set("value", 400);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}
