// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
��·�õ�ʯͷ������ɢ�ҵضѷ��ţ�����һЩ��ɢ�Ĺ��ߡ����ϵĵط��и���
����һ�����Ǹո��ٳ����ġ��ƺ�����������������ﲻ������Ӵ����������š�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"txnd",
  "east" : __DIR__"zl",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",3);
	set("coor/y",-14);
	set("coor/z",0);
	setup();

}
