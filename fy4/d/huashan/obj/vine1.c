// annie. 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
	set_name("����", ({ "vine", "����" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","inside");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "Ƭ");
	    set("long", "ï�ܵĹ��ٸ�������Ƭ���±ڡ�\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
