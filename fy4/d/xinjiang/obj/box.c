
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({ "box", "iron box"}) );
        set_weight(300);
        set_max_encumbrance(800);
        if (clonep())
           	set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "һ��������������С���������Ű�����(open)\n");
		set("no_drop", 1);
		set("value", 1);
        set("prep", "in");
        }
		::init_item();
}

int is_container() {return 1;}

void init()
{
   	add_action("do_open","open");
}

int do_open(string arg)
{
	object		me, ob, item;
	int		kar;
	
	me = this_player();
	ob = this_object();
        if (me->is_ghost())
        	return notify_fail("����޷��������ء�\n");
        if( !arg || arg != "box" )
        	return notify_fail("��Ҫ��ʲô��\n");
        if(ob->query_temp("marks/opened")) return 0;
		message_vision("$NС�ĵ���Ҫ��$n�򿪣�������\n", me, ob);
		kar = me->query_kar();
		if(random(kar) < 11) { 
		message_vision(HIR "ֻ������������һ�������Ŵ�$n�������ֻ��ɫ�����룬������$N�����ϣ�\n"NOR, me, ob);
		me->receive_wound("kee",20);
		me->set_temp("last_damage_from","�󴥻��أ�����Ӱ��������\n");
		me->apply_condition("no_shadow", 10);
		message_vision(HIR "$N�������ϵĶ���\n"NOR, me);
	}
	else {
        	message_vision("$N���ڰ�$n���ˡ�\n", me, ob);
            set("long", "һ���⼣�߰ߵ����У��и��Ѿ������ˡ�\n");
            switch (random(2)) {
                case 0:
                      item = new(__DIR__"jade");
                      item->move(ob);
                   	break; 
                case 1:
                      item = new(BOOKS"dodge_75");
                      item->move(ob);
                  	break;
                }
			ob->set_temp("marks/opened",1);
	}
        return 1;
}

