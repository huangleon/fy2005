
inherit ITEM;
void create()
{
	set_name("����" , ({ "willow pipe" , "liu di", "pipe"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��С���ѡ�\n");
		set("value", 100);
		set("holiday", "������");
	}
	::init_item();
}



