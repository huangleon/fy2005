
inherit ITEM;
void create()
{
	set_name("�����ϲ�", ({ "jade cicada","cicada"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һö������͸�İ����ϲ����������ѵ�һ������Ʒ��\n");
		set("unit", "ö");
		set("value", 3333);
	}
	::init_item();
}

