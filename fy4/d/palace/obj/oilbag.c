
inherit ITEM;

void create()
{
	set_name("��Ƥ��", ({ "oilbag" , "��Ƥ��"}) );
	set_weight(500 + random(8000));
	set_max_encumbrance(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ˮ����Ƥ����������ˮ��ʹ�á�\n");
		set("value", 1);
		set("waterproof",1);
	}
}

int is_container() { return 1; }
