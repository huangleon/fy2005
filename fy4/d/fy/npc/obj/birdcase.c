inherit ITEM;

void create()
{
	set_name("��������", ({ "birdcase"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("contains",1);
	set("skylark",0);
	set("closed",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����µ�С�������ʷ��Σ�һ�������ϳ�(open)���š�\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

void init()
{
	if(this_player()==environment())
		add_action("do_open","open");
}

int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "birdcase" )
                return notify_fail("��Ҫ��ʲô��\n");
	else
		return notify_fail("������û����װ����ץֻ����˵�ɣ�\n");
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
