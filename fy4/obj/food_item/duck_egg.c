inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ѽ��", ({ "duck egg","egg" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������˵����Ѽ����\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
	::init_item();
}


void init() {
	::init();
	if (!query("decaying")) {
		call_out("badegg", 180);
		set("decaying",1);
	}
	return;
}

void badegg() {
	set("long", "�Ѿ��������ʵĵ���ɢ������ζ��\n");
	set("name", "����");
	set("value", 0);
	return;
}
