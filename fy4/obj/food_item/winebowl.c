// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�����", ({ "wine bowl", "bowl" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ִɴ��롣");
		set("unit", "��");
		set("value", 50);
		set("max_liquid", 5);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "��Ҷ��",
		"remaining": 5,
		"drunk_apply": 3,
	]) );
    ::init_item();
}

