// teapot.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����", ({ "tea pot", "pot" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������װ�ü���ˮ������װ�Ķ����йɹ�ζ����\n");
		set("unit", "��");
		set("value", 0);
		set("max_liquid", 10);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"name": "�ں����Ĳ�ˮ",
		"remaining": 10,
		"drunk_apply": 70,
	]) );
	::init_item();
}
