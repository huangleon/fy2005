// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���е�");
        set("long", @LONG
�����ϵͣ�����·�涼����б�ġ���Ȼ������߲��ã�����Ļ���ȱ�ĵط�
���ࡣ·�߶ѷ���һ����ľͰ���д���С������װ����ˮ���ƺ����ڽ���ʱ�Ȼ���
�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tt",
//  "east" : __DIR__"zddm",
]));
        set("objects", ([
          __DIR__"obj/woodbarrel": 3,
                        ]) );
        set("indoors", "cave");
	set("coor/x",6);
	set("coor/y",-4);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

/*
int valid_leave(object obj, string dir){
	object ma;
	if(dir == "west"){
		if(!obj->query("vendetta/authority") && present("mao zhan", this_object())){
			ma = present("mao zhan", this_object());
			return notify_fail(ma->name()+"����ס�����·��\n");
		}
	}	
	return 1;
}
*/
