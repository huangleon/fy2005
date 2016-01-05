// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
        set("short", "��������");
        set("long", @LONG
һ̶��ˮ��ͣ��ð�����ݣ���֦��Ҷ��ͬ���Ƶİ׹����гߺ񡣼��鰵��ɫ��
������ʯ���ں�ˮ���룬���沼���˸���ʬ����̶ˮ��Ư���Ŷζο�ľ����Щ��ɢ
�����������̡�
LONG
        );
        set("exits", ([ 
 		 "west" : __DIR__"zhaoze4",
	]));
        set("objects", ([
                __DIR__"npc/dragon" : 1,
       	]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
//	set("no_curse",1);
	set("coor/x",0);
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
}