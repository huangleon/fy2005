inherit ITEM;

void create()
{
	set_name("����", ({ "gong xiang", "����"}) );
	set_weight(10);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "֧");
	    set("long", "һ֧ȼ�ŵĹ��㡣\n");
	    set("value", 10);
	}
	::init_item();
}

