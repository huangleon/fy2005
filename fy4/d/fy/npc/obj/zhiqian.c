
inherit ITEM;
void create()
{
	set_name("ֽǮ" , ({ "zhiqian" , "ֽǮ"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ֽǮ\n");
		set("value", 100);
	}
	::init_item();
}



