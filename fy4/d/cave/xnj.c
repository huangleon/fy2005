// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���Ͻ�");
        set("long", @LONG
��ʯ��ᾣ���޺�����������������ͻ�ˮ��ɢ����������Ż�ĳ����������ϸ
���Ļ������Կ����������ͳ�ˮ���䶯�ĸ������˶��ĵĳ��档���������ﾹ����
���õ�ʬ�塣��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
//  		"north" : __DIR__"ntxm",
  		"east" : __DIR__"txnd",
	]));
    set("objects", ([
        __DIR__"npc/xiaowu": 1,
        __DIR__"obj/trash": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",1);
	set("coor/y",-14);
	set("coor/z",0);
	setup();
}

/*
int valid_leave(object obj, string dir){
	object ma;
	if(dir == "east"){
		if(!obj->query("vendetta/authority") && present("ding gan", this_object())){
			ma = present("ding gan", this_object());
			return notify_fail(ma->name()+"����ס�����·��\n");
		}
	}	
	return 1;
}
*/
