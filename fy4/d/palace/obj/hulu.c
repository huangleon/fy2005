
inherit ITEM;

void create()
{
	set_name("�Ͻ��«", ({ "hulu" , "�Ͻ��«"}) );
	set_weight(500+random(160000));
	set_max_encumbrance(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ɷźöණ���ĺ�«\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
