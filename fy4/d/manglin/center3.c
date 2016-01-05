#include <ansi.h>
inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "ç��֮��");
        set("long", "����"YEL"����"NOR"���죬�����ܲ���Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ�����ҹ��
��������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������Х�Ǻ������ȷ�
Ʈ�����ʡ�
"
        );
        set("exits", ([ /* sizeof() == 4 */
	  "east" : __DIR__"groupe3",
	  "west" : __DIR__"groupw3",
	  "north" : __DIR__"groupn3",
	  "south" : __DIR__"groups3",
	
	]));
	set("item_desc", ([
		"tree":	"�����кܶ�ͻ������֦���������������ȥ�������⣩������\n",
		"��":	"�����кܶ�ͻ������֦���������������ȥ�������⣩������\n",
		"����":	"�����кܶ�ͻ������֦���������������ȥ�������⣩������\n",
	]));
	
	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",-40);
	setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                return 0;
        }
        if( arg == "tree" || arg == "����" || arg == "��")
        {
	        me = this_player();
        	if (me->is_busy() || me->query_temp("manglin/climb"))
        		return notify_fail("��������æ��\n");
        	message_vision("$Nץ��ͻ������֦��������˳������������ȥ��\n", me);
        	me->start_busy(2);
        	me->set_temp("manglin/climb",1);
        	call_out("fliping",3,me);
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}

int fliping(object me)
{
	if (!objectp(me))	return 1;
	
	me->delete_temp("manglin/climb");
	if(!interactive(me) || environment(me) != this_object()){
		return 1;
	}
	
	if(!me->is_ghost()){
		me->move(__DIR__"top3");
		message_vision("$N˳����������������\n", me);
	       	me->stop_busy();
	}
        return 1;
}
