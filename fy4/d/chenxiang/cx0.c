// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����Ǳ���");
        set("long", @LONG
���źܴ󣬶��Һ��£�һ�����ǽ���Ž������ġ���ǰ�Ĺ㳡����һ�ÿ�С
�����ر�Ŀɰ�������ɫ��ʯש�ҳ�һ���൱�����·����ʯש����ǻ�û��ĥ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"chenxiang3",
  "southeast" : __DIR__"cx1",
]));
        set("objects", ([
        __DIR__"npc/cg": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
