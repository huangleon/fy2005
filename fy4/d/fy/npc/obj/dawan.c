
inherit ITEM;

void create()
{
	set_name("����", ({ "dawan", "wan" }) );
	set_weight(700);
   set_max_encumbrance(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ǵĴ��롣\n");
		set("unit", "��");
		set("value", 50);
	}

	::init_item();
}
int is_container() { return 1; }


// ���p��dancing_faery@hotmail.com

