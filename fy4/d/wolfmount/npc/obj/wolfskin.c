inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
    set_name(RED"�Ǿƴ�"NOR, ({ "wolf skin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ̳���㷼�����޺���Ѫ�����ơ�\n");
		set("unit", "��");
		set("value", 2000);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "�Ǿ�",
		"remaining": 15,
		"drunk_apply": 30,
	]) );
   	::init_item();
}
