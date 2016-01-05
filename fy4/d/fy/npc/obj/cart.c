
inherit ITEM;

void create()
{
    set_name("�ڳ�", ({ "silver cart", "cart"}) );
    set_weight(300000);
    set("no_get", 1);
    set("no_reset",1);
    set_max_encumbrance(80000000);
    set("unit", "��");
    set("long", "һ����������ڳ���������Ž�ʨ���졣\n");
    set("closed", 1);
    set("value", 2000);
	::init_item();
}

int is_container() {return 1;}

void init()
{
    add_action("do_open","open");
    add_action("do_close","close");
}

int do_close(string arg)
{
    object		me, ob;

    me = this_player();
    ob = this_object();
    if(arg != "cart" && arg != "silver cart")
        return notify_fail("��Ҫ����ʲô��\n");
    message_vision("$N��$n�Ź����ˡ�\n", me, ob);
    ob->set("closed",1);
    return 1;
}

int do_open(string arg)
{
    object me, ob;
	
    if(arg != "cart" && arg != "silver cart")
        return notify_fail("��Ҫ��ʲô��\n");
    me = this_player();
    if (objectp(ob=present("li biaotou",environment())))
        return notify_fail(ob->name()+"������һ�ۣ���Ҫ��ʲô��\n");
    this_object()->set("closed",0);
    message_vision("$N��$n�Ǵ򿪡�\n", me, this_object());
    return 1;
}

int is_closed()
{
    return ((int) this_object()->query("closed"));
}
