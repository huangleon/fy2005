inherit ITEM;

void create()
{
	set_name("����", ({"bamboo shoot", "shoot"}) );
	set_weight(100);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ��������\n");
	    set("value", 50);
	}
	::init_item();
}



