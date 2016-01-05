// pipe.c

inherit ITEM;

void create()
{
        set_name("ʥ��",({ "saint pipe","pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("long", "һ�����ӣ���֪������ʲô����Ľ����ɵġ�\n");
        }
	::init_item();
}

void init()
{
        add_action("do_blow", "blow");
}

int do_blow(string arg)
{
        if( arg != "pipe" ) return 0;

        message_vision("$N����һ��" + this_object()->name() + "����һ����\n", this_player() );
        environment(this_player())->pipe_notify();

        return 1;
}
