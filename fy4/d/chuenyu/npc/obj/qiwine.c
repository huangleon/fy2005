
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��Ƥ�ƴ�", ({ "wineskin", "skin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ƥ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 50);
		set("max_liquid", 20);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "��Ҷ��",
		"remaining": 20,
		"drunk_apply": 10,
	]) );
	::init_item();
}
