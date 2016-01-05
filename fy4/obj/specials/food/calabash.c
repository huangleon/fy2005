// bottle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���«", ({ "green calabash", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ������ɫ�ĺ�«������͸����ɫʮ������ϲ����\n");
		set("unit", "��");
		set("value", 1);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "��Ȫˮ",
		"remaining": 60,
	]) );
}
