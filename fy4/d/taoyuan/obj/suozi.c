
inherit ITEM;

void create()
{
	set_name("����", ({ "suo zi" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������޲����������ӡ�\n");
		set("value", 100);
	}
    ::init_item();
}



