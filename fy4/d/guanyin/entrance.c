// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ʯ���Ե");
        set("long", @LONG
���ﲻ�������ѵ���ɳĮ�ľ�ͷ����ֱ���ǵ�����صľ�ͷ������ǰ�ߣ���Ҫ
������Ͳ�������Ԩ�С�ǰ�����ʯ�壬�ޱ��޼ʣ���Ҳ����ǰ�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : AREA_QUICKSAND"desert2",
  "north" : __DIR__"road1",
]));

        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
