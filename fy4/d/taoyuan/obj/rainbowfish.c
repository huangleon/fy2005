inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("���С��", ({ "rainbowl fish", "fish", "wu_cai fish" }) );
    set_weight(120);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ�����������С�㣬�������������ɫ��\n");
        set("unit", "��");
        set("value", 500);
        set("food_remaining", 3);
        set("food_supply", 60);
    	set("marks/catfood", 1);
    }
    ::init_item();
}

void init() {
	::init();
	call_out("inWater", 30);
}

void inWater() {
	object container;
	
	container = environment(this_object());
	if(container->name() != "С���" || !container->query("marks/haswater")) {
		set("long", "С�����ˣ�ԭ��ɫ�����޵�����۱�ĺ��޹���\n");	
		set("name", "�����˵���");
		set("marks/catfood", 0);
		set("value", 0);
	}
}
