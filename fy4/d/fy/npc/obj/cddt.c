// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ɴ���", ({ "dawan", "wan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������ľ�̩������\n");
		set("unit", "��");
		set("value", 1000);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "soup",
		"name": "�ɶ�����",
		"remaining": 5,
		"drunk_apply": 0,
	]) );
	::init_item();
}
