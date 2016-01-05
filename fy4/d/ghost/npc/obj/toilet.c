#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("������Ͱ", ({ "toilet", "������Ͱ"}) );
        set_weight(300);
        set("no_get", 1);
        set("no_shown", 1);
        set_max_encumbrance(800000);
	set("unit", "��");
	set("long", "һ��Ů�����õĽ�����Ͱ��\n");
	set("closed", 1);
	set("value", 2000);
        set("objects", ([
                AREA_GHOST"npc/butterfly": 1,
        ]));

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
        if( !arg || arg != "toilet" )
                return notify_fail("��Ҫ����ʲô��\n");
       	message_vision("$N��$n�ǹ����ˡ�\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object		me, ob;
	int		kar;
	
        if( !arg || arg != "toilet" )
                return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	ob = this_object();
	ob->set("closed",0);
       	message_vision("$N��$n�Ǵ򿪡�\n", me, ob);
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
