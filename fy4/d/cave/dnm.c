// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
����ո��պõ�ש���ѷ�������������ʵ�ɳʯ���������ƺ���Ҫ����һ��
���ģ�Ĺ��̡�·�߱����˸��󶴣�ֱͨ����ĵ��ºӣ������и����ӣ������и�
ľͰ���ƺ���������ˮ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zl",
  "east" : __DIR__"tdnd",
]));
        set("indoors", "cave");
	set("coor/x",6);
	set("coor/y",-14);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
}
