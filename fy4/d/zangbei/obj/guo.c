inherit ITEM;
inherit F_LIQUID;

int tianyi();

void create()
{
	set_name("����", ({ "guo"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ﻹ��ð��������ɢ����һ�������㡣\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "����",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
	set("liquid/drink_func",(: tianyi() :));
	::init_item();
}


int tianyi(){
	this_player()->apply_condition("tianyi",20);
	return 1;
}