// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ţƤ�ƴ�", ({ "maoskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 2000);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "����ę́",
		"remaining": 15,
		"drunk_apply": 10,
	]) );
	::init_item();
}
