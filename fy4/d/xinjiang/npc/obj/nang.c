// Copyright (C) apstone, inc.

inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("��", ({ "nang" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ӲӲ�ģ���ɫ���ڵ�Բ����\n");
		set("unit", "��");
		set("value", 10);
		set("food_remaining", 10);
		set("food_supply", 60);
	}
	::init_item();
	
}
