inherit ITEM;

void create()
{
	set_name("��ë", ({ "rongmao" , "deer hair", "hair", "��ë"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ϸ�ܵ���ë��\n");
		set("value", 100);
	}
    ::init_item();
}



