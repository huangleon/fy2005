// Copyright (c) apstone, inc.
inherit ITEM;
inherit F_LIQUID;
void create()
{
	set_name("ţƤ�ƴ�", ({ "ox skin", "skin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ������װ�ðˡ�������Һ�塣\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "������",
		"remaining": 15,
		"drunk_apply": 30,
	]) );
	::init_item();
}
