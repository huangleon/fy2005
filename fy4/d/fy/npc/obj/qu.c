
inherit ITEM;
void create()
{
	set_name("�����˵���" , ({ "qu" , "dead qu"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���װ׵������˵���\n");
		set("value", 0);
	}
	::init_item();
}



