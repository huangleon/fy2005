inherit ITEM;

void create()
{
	set_name("����", ({ "pot", "����", "����", "��"}) );
	set_weight(700);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ�����裬�������Ÿ�ʽ�軨��\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

