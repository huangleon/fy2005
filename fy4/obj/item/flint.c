inherit ITEM;

void create()
{
    	set_name("��ʯ", ({ "flint"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", "һ���������������������ʯ��\n");
        	set("value", 10000);
    	}
    	::init_item();
}

void init()
{
        add_action("do_light", "use");
}


int do_light(string arg)
{
        if( arg != "flint" ) return 0;

        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "���˼��¡�\n");
        environment(this_player())->light_notify(this_object(), 0);
        return 1;
}
