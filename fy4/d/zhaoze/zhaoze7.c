// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ܲ��ľ����������̣�����ͨ��������ķ��򡣵Ͱ���С���Ե�ס���ߣ�
ʹ�˱治�巽�򡣵��²������õĿ�Ҷ����������ġ�ż����һ�������ݴӵ��ϵ�
��ˮ��ӿ��������������Ż�Ĵ̱���ζ��
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"zhaoze6",
]));

        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
		"woods" : "����С����(woods)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
		"С����" : "����С����(woods)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"
        ]) );
        set("objects", ([
                __DIR__"npc/monster2" : 1,
                __DIR__"npc/monster3" : 1,
       ]) );
       set("outdoors", "zhaoze");
       set("no_fly",1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{	object ob,room;
	if( interactive( ob = this_player())) {
    		if(ob->query_skill("force",1) < 150) {
			if (!room=find_object(__DIR__"edge.c"))
				room = load_object(__DIR__"edge.c");
			ob->move(room);
			message_vision(HIR"$N�������������������˻�����\n\n"NOR, ob);
		}else if (userp(ob) || userp(ob->query("possessed")))
				ob->apply_condition("zhaoze",10);			
	}
	add_action("do_chop","chop");
}

int blowing(object ob, object room)
{
	int i;
	int damage;
        if(  ob && environment(ob) == room )
	{
		tell_object( ob , HIR "\n\n���µ�����ͻȻ�ѿ���һ�ų��ȵĵػ�����Ȫ���������\n\n"NOR);
		ob->receive_wound("kee", random(100)+10);
		ob->set_temp("last_damage_from","�ڻ������һ���������\n");
		COMBAT_D->report_status(ob,1);
		if( environment(ob) == room )
			call_out("blowing",random(10)+1, ob);	
	}
	else
		return 1;
}

void reset()
{
	::reset();
        remove_call_out("blowing");
        delete("exits/south");
        delete("exits/west");

}

int valid_leave(object me, string dir)
{
        if ((query("exits/west") && dir == "west") 
        	|| (query("exits/south") && dir=="south"))
        if (present("fire giant", this_object()))
        	return notify_fail("����鵲ס�����ȥ·��\n");
        remove_call_out("blowing");
	return 1;
}

int do_chop(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "bush" || arg == "����" || arg == "woods" || arg == "С����")
        {
        	me = this_player();
        	obj = me->query_temp("weapon");
        	if( !obj )
        	{
        		write("������֣���ô����\n");
        		return 1;
        	}
	        if( obj->query("jungle"))
	        {
			if( arg == "bush" || arg == "����")
			{
		        if( !query("exits/south") ) {
			        set("exits/south", __DIR__"zhaoze3");
			        message_vision(sprintf("$N�����е�%s����һ�����ϵ�·��\n",obj->name()),
			                me);
								}
			        else
			        message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),
			                me);
			}
			else
		        {
			        if( !query("exits/west") ) {
			        set("exits/west", __DIR__"center");
			        message_vision(sprintf("$N�����е�%s����һ��������·��\n",obj->name()),
			                me);
							        }
			        else
			        message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),
			                me);
			}
			me->start_busy(1);
		}
	        else
	        	message_vision(sprintf("$N�����е�%s������ľ���һ���ҿ���\n",obj->name()),
	                me);
        }
        else
         	write("��Ҫ����ʲô��\n");
        return 1;
}

