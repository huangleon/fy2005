inherit ITEM;
void create()
{
	set_name("������", ({ "birdcage"}) );
	set_weight(500);
	set_max_encumbrance(1000);
	set("closed",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������͵ľ��������Ѿ����õ�û�������ˡ�\n");
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
        if( !arg || arg != "birdcage" )
                return notify_fail("��Ҫ��ʲô��\n");
	else
		return notify_fail("��������������ź͹���ûʲô����\n");
}
