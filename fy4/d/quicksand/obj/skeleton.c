
inherit ITEM;

void create()
{
	set_name("һ�߿�Ǭ�ĺ���", ({ "skeleton" , "����"}) );
	set_weight(400000);
	set_max_encumbrance(500000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�߿�Ǭ�ĺ��ǡ�\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


