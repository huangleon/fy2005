
inherit ITEM;
void create()
{
	set_name("С�糵" , ({ "small toy" , "toy"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ӭ��ͻ�ת��С�糵\n");
		set("value", 100);
	}
	::init_item();
}



