// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ʯ�����");
        set("long", @LONG
����ǰ�ߣ�����ǰ��һ���߲����ƵĹ�ʯ��壬����׷��Ķ��޵���ǰ�档��
ʯ���о�����С·���������ۣ�����������ǡ����Ȼ��ͨ��ʯ��Ⱥ�С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"road3",
  "west" : __DIR__"road1",
]));

        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
