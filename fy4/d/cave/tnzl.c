// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������·");
        set("long", @LONG
·������Խ��Խ���ˣ���������Կ����ϱߵĶ������ƺ��ͽ���һ���롣�ϱ�
�ķ���ȫ���ڽ��£������еĵ��ƻ��׺��һƬ�ڰ���������ҹ���ө��档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tnzm",
  "south" : __DIR__"zl",
]));
        set("objects", ([
          __DIR__"npc/maozhan": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-8);
	set("coor/z",0);
	setup();
}


int valid_leave(object obj, string dir){
	object ma;
	if(dir == "north"){
		if(!obj->query("vendetta/authority") && present("mao zhan", this_object())){
			ma = present("mao zhan", this_object());
			return notify_fail(ma->name()+"����ס�����·��\n");
		}
	}	
	return 1;
}
