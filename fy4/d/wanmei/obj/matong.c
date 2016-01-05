// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����С��Ͱ", ({ "matong", "tong" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������С��Ͱ��һ�������������õĶ�������\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 25);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "Ư��һЩ������ˮ",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
    ::init_item();
}
