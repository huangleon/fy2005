
inherit ITEM;
void create()
{
	set_name("ֽ��" , ({ "zhihua" , "ֽ��"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ֽ��\n");
		set("value", 100);
	}
	::init_item();
}



