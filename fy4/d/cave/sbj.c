// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ʳ����Σ������������ǡ���һ�����ڽ����һ����������������
�ġ������������ˮ��������������ȥ������ȫ�������ӳ����ˡ�
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"sbm",
  		"south" : __DIR__"btxm",
	]));
    set("objects", ([
        __DIR__"npc/mabian": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

int valid_leave(object obj, string dir){
	object ma;
	if(dir == "east"){
		if(!obj->query("vendetta/authority") && present("ma bian", this_object())){
			ma = present("ma bian", this_object());
			return notify_fail(ma->name()+"����ס�����·��\n");
		}
	}	
	return 1;
}
