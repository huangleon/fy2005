
inherit ITEM;

void create()
{
	set_name("ϸ����", ({ "string" , "xi xiang"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��������ϸ���ߡ�\n");
		set("value", 50);
	}
    ::init_item();
}



