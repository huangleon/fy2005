// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ʯ������");
        set("long", @LONG
�磬�����ɳ�����������ȼ䣬��ƽ����һ�����ع���֮�⣬��ɽ���������
һ�ߡ����������ȼ䣬������ɳ��ȴ����Ҳ�Ʋ����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sand",
  "south" : __DIR__"deep2",
  "east" : __DIR__"deep",
]));

	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
