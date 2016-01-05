// skin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ţƤ�ƴ�", ({ "wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");

		set("max_liquid", 15);
	}
	set("value", 0);
	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "�����",
		"remaining": 15,
		"drunk_apply": 70,
	]) );
	::init_item();
}
