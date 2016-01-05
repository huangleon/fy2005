inherit ITEM;

void create()
{
    set_name("��ߡ��", ({ "lighter" , "��ߡ��", "huozhizi"}) );
    set_weight(5);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("lighter",1);
        set("long", "һ�������������Ļ�ߡ�ӡ�\n");
        set("value", 20);
    }
    ::init_item();
}

void init()
{
        add_action("do_light", "use");
}

int do_light(string arg)
{
        if( arg != "lighter" ) return 0;

        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "���˼��¡�\n");
        environment(this_player())->light_notify(this_object(), 0);

        return 1;
}


