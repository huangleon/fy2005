// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "��������");
        set("long", @LONG
�������ߣ����ڱ�ֱ�������޷�������һ������Ѻ����������������кܶ��
�ѷ죬���ǵ�����һ�εε�ˮ�飬������·Ū��ʪʪ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"twt",
  "west" : __DIR__"sbm",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
