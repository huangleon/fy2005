// 
inherit ITEM;

void create()
{
    set_name("����",({ "gao", "mattock", "tie gao" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
    set("value",1);
        set("material", "steel");
        set("long", "һ��Լ���߶೤�����䣬���������ھ�dig����\n");
    }
    ::init_item();
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg)
{

        message_vision("$N�ó�һ��" + this_object()->name() + "��\n", this_player() );
        environment(this_player())->dig_notify(this_object(), 0);

        return 1;
}
