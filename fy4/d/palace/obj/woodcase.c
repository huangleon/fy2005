
inherit ITEM;

void create()
{
	set_name("������", ({ "woodcase" , "������"}) );
	set_weight(10000);
	set_max_encumbrance(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("prep", "under");
		set("long", "һ�������ӣ�ľ�Ϻܺã����滹������ͭ��\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


