
inherit ITEM;
inherit F_FOOD;

void create()
{
        string *order=({"С�ײ�", "С���", "�����", "��ײ�",
"�²�","�ඹ","�㶹","�̶���"});
	set_name(order[random(8)], ({ "vegetable" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ÿ��˵����\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 3);
		set("food_supply", 6);
	}
    ::init_item();
}
