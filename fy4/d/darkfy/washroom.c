
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "ϴ�µ�");
        set("long", @LONG
����һ��ϴ�µ꣬��������Ǯ�˽��·�������ϴ�ĵط���������ϰ���һ
��������͵���̫�ţ�����һ�ˣ��޶���Ů��������ϴ�µ�΢��������ά����
�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ecloud3",
]));

        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );
        set("coor/x",30);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}

