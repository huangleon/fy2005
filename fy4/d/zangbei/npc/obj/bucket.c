// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ˮͰ", ({ "bucket"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ˮͰ��\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 20);
	}
	::init_item();
}
