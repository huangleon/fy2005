// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С����");
        set("long", @LONG
˵�Ǹ���������ʵ�������Ա����ڽ�ȥһ�飬���˵����һ����ͬ����С
�������Ǻ�ͬ�Աߵ�һ��С���ݡ���������������һ�����Ӻ�һ��С����������
������ڿ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yd",
  "south" : __DIR__"twt",
]));
        set("objects", ([
        __DIR__"obj/bed": 1,
        __DIR__"obj/desk": 1,
        __DIR__"npc/maoye": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",-5);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
