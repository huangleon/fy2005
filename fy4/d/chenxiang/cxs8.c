// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���С·");
        set("long", @LONG
�����ǳ�������ţ������������Ե���ܶ�Ӣ�ۺú��������������߾���Ҳû
�л����ˡ����������ո�ǿ����ò�Ҫ���������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs7",
  "south" : AREA_ZHAOZE"edge",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
