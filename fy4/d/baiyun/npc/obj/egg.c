inherit F_FOOD;
inherit ITEM;

void create()
{
    	set_name("���󼦵�", ({ "egg"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("long", "һ�����˿ǵİ��󼦵���\n");
        	set("unit", "��");
        	set("value", 200);
        	set("food_remaining", 4);
		set("food_supply", 40);
		set("material", "food");
	}
	::init_item();
}
