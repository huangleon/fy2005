
inherit ITEM;
void create()
{
	set_name("�ϵ�", ({ "broken flute","flute"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ѿ��µ�ľ�ѣ��������е�ȴֻ���۶ϵİ�ء�\n");
		set("unit", "��");
		set("value", 0);
		set("real",1);
	}
	::init_item();
}

