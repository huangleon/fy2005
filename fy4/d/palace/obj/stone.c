
inherit ITEM;

void create()
{
	set_name("��ʯ", ({ "stone" , "��ʯ"}) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("prep", "under");
		set("long", "��ɫ�ľ�ʯ��������������˵�ɫ��\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


