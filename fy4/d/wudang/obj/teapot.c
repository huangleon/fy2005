inherit ITEM;

void create()
{
	set_name("�ɲ��", ({ "tea pot", "���"}) );
	set_weight(100);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "ֻ");
	    set("long", "һֻ�ɲ�������滭���䵱ɽˮ��\n");
	    set("value", 100);
	}
	::init_item();
}

