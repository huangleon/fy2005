inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("������", ({ "jzds", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�̼ҳ�С�ˡ�\n");
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}


int finish_eat()
{
        set_name("����", ({"panzi"}));
	set("value",200);
        set("long", "һֻ���׶��񻨵ľ�̩�������ӡ�\n");
        return 1;
}

void init() {
	::init();
	if (!query("in_decay")) {
		set("in_decay",1);
		call_out("badmeal", 180);
	}	
}

void badmeal() {
	set("long", "һ�̼ҳ�С�ˣ���ϧʱ��̫�����Ѿ��������ˡ�\n");
	set("name", "���˵�С��");
	set("value", 0);
}