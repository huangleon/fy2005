// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
ʯ���о���һ��С·���������ۣ����������������ٶ��߼���Ҳ�޷������
���......����֮������˭�������Ҳ�������׳�ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"deep2",
  "east" : __DIR__"road3",
  "north" : __DIR__"deep",
]));

        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
