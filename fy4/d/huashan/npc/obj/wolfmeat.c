inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("���⸬", ({ "wolfmeat" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "��Ұ���⸬���ƺ���ӥ�Ŀɿ�ʳ� \n");
		set("unit", "��");
		set("value", 60);
        	set("food_remaining", 6);
		set("food_supply", 90);
        	set("material", "meat");
        	set("hawk_food",1);
	}
        ::init_item();
}

