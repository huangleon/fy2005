
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({ "box"}) );
        set_weight(300);
        set_max_encumbrance(800);
	set("unit", "��");
	set("long", "һ��������������С���������Ű�����(open)\n");
	set("closed", 1);
	set("value", 200);
	::init_item();
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
		 add_action("do_close","close");
}

int do_close(string arg)
{
	object		me, ob;

	me = this_player();
	ob = this_object();
        if( !arg || arg != "box" )
                return notify_fail("��Ҫ����ʲô��\n");
       	message_vision("$N��$n�ǹ����ˡ�\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object		me, ob;
	int		kar;
	
        if( !arg || arg != "box" )
                return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	ob = this_object();
	message_vision("$NС�ĵ���Ҫ��$n�򿪣�������\n", me, ob);
	kar = me->query_kar();
	if( kar < 29 || random(5) != 3) { 
		message_vision(HIR "ֻ������������һ�������Ŵ�$n�������ֻ��ɫ�����룬������$N�����ϣ�\n"NOR, me, ob);
		me->apply_condition("no_shadow", 10);
		message_vision(HIR "$N�������ϵĶ���\n"NOR, me);
	}
	else {
		ob->set("closed",0);
        	message_vision("$N���ڰ�$n���ˡ�\n", me, ob);
	}
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
