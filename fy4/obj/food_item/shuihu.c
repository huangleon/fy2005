// teapot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("ˮ��", ({ "water pot", "pot" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ����ˮ�������װ�ü���ˮ��\n");
		set("unit", "��");
        set("value", 50);
        set("max_liquid", 20);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
        "name": "��ˮ",
		"remaining": 10,
	]) );
	::init_item();
}
