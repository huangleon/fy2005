
inherit ITEM;

void create()
{
	set_name("����", ({ "string" , "yu xian"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������������޲��������ߡ�\n");
		set("value", 50);
	}
    ::init_item();
}



