// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
������ʵ��һ�����ұ��ϴ�����Ķ����������߾���������Ķ����ǡ����ߵ�
�����ر�󣬺������졣������ң�����û�а취֪�������Ǵ�ʲô�ط������ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tdbd",
  "east" : __DIR__"dbj",
]));
        set("indoors", "cave");
	set("coor/x",5);
	set("coor/y",10);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
}
