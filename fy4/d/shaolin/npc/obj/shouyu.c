// pipe.c

inherit ITEM;

void create()
{
        set_name("��������",({ "shouyu" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֽ");
                set("material", "paper");
				set("no_stack",1);
				set("no_give",1);
                set("long", "�����ĺ��ױ�д�µ���������ܲؾ���������壩����\n");
		set("lore",1);
        }
}

void init()
{
        add_action("do_wave", "wave");
}

int do_wave(string arg)
{
        if( arg != "shouyu" ) return 0;
        message_vision("$N�ӻ����ó�һֽ" + this_object()->name() + "���˶���\n", this_player() );
        environment(this_player())->shouyu_notify();

        return 1;
}
