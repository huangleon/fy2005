inherit ITEM;

void create()
{
	set_name("ҹ����", ({ "pearl" , "ҹ����"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ں�ҹ���������ҹ���顣\n");
		set("value", 1000);
	}
    ::init_item();
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "pearl" ) return 0;

        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
        environment(this_player())->light_notify(this_object(), 1);

        return 1;
}


