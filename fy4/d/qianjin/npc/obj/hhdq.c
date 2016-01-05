// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("С��", ({ "gold cup", "cup" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��СС�Ľ𱭣����װ��һ�����ڵľơ�\n");
		set("unit", "��");
		set("value", 2000);
		set("max_liquid", 2);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "�ƺӴ���",
		"remaining": 2,
		"drunk_apply": 20,
	]) );
}
