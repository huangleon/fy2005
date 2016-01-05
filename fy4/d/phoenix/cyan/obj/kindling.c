inherit ITEM;

void create()
{
    set_name("����", ({ "kindling" }) );
    set_weight(5);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ��СС�Ļ��֡�\n");
        set("value", 0);
    }
    ::init_item();
}

void init()
{
       add_action("do_light", "use");
}

int do_light(string arg)
{
        if( arg != "kindling" ) return 0;

        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "���˼��¡�\n");
        environment(this_player())->light_notify(this_object(), 0);
        environment(this_player())->kindling_notify(this_object(), 0);

        return 1;
}


