inherit ITEM;

void create()
{
	set_name("����", ({ "��", "tree", "����" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ�þ޴�����������ƺ�������չ���Ȼ���ڽ��ڵ��������ֳ������̵���ѿ��\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

