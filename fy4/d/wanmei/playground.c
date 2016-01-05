// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��������÷ɽׯ�ĺ�ɽ�¡�������ɽ��Ұ��÷��֮�����һ��������̲�ƺ��
����ɫ������Ұ������׺�ţ���������������һ��С�Ӻᴩ�����������С�㲻
ʱ�����Ծ��ˮ�档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"backyard",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/child" :1,
		__DIR__"obj/river" : 1,
                        ]) );
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}



void init()
{		
	add_action("do_swim","swim");
	remove_call_out("do_check");
	call_out("do_check",10);
}


int do_check()
{
	object *inv;
	int i;
	object river;
	river = present("river",this_object());
	if(river)
	inv = all_inventory(river);
	for(i=0;i<sizeof(inv);i++)
		{
		if(inv[i]->query("floating"))
			{
				tell_object(this_object(),"С��Ư�˹�����������\n");
				inv[i]->set("no_drop");
				set("exits/north", __DIR__"upriver");
				call_out("close_path",10);
				break;
			}	
		destruct(inv[i]);
	}
}


void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","С��Ư���ˡ�������\n", this_object() );
        delete("exits/north");
}


int do_swim()
{
	object me;
	object room;
	me = this_player();
	message_vision("$Nһ������������С�������\n",me);
	room = load_object(__DIR__"river");
	me->move(room);
	return 1;	
}
