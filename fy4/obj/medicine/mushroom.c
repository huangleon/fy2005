inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("СĢ��", ({ "mushroom" , "СĢ��"}) );
    set_weight(30);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
        set("unit", "Щ");
        set("long", "һЩ��ɫ��СĢ���� \n");
        set("value", 1);
        set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");         
    }
	::init_item();
}

/*
int finish_eat()
{
	object me;
	
	me = this_player();
	me->apply_condition("mushroom", 1+random(6));
}

*/