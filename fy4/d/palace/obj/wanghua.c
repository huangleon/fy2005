
inherit ITEM;

void create()
{
	set_name("���껨", ({ "wanghua" , "���껨"}) );
	set_weight(5);
	set_max_encumbrance(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("prep", "on");
		set("long", "һ�ñ��̵Ĳ�\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
