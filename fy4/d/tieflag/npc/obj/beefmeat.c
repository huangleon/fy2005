inherit F_FOOD;
inherit ITEM;

void create()
{
    set_name("ţ���", ({ "beef meat","meat"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ����ζ��ţ���,����ȥ���ͳԵ�����.\n");
		set("unit", "��");
        set("value", 1000);
        set("food_remaining", 4000);
		set("food_supply", 1000);
		set("material", "food");
	}
	::init_item();
}
