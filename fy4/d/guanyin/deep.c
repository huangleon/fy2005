// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ʯ���");
        set("long", @LONG
��Щʯ�壬�����������������������е�·���������������˱仯֮������
������İ���ͼһ�㣬���˾�����֮�����⣬���������֮���������ǹ��񹦣�
�����Ѳ⡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"road3",
  "south" : __DIR__"road4",
  "west" : __DIR__"narrow",
]));

        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
