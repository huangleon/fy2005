inherit ITEM;

void create()
{
    set_name("���ܶ�", ({"tengluo", "vine", "teng luo"}) );
    set_weight(500);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else
    {
        set("unit", "��");
        set("long", @LONG
����һ����ɫ�����ܣ����ܵ�Ƥ���Ͷ���ʵ��������һ���ܳ������ӡ�������壩
LONG
            );
        set("value", 0);
    }
    ::init_item();
}

int do_make(string arg)
{
    object ob;
    object me=this_player();
    message_vision("$N��������ָ���������ܵ�Ƥ���������´����һ��������\n",
                   me);
    ob=new(__DIR__"brope");
    ob->move(me);
    destruct(this_object());
    return 1;
}

void init()
{
    add_action("do_make","make");
}


