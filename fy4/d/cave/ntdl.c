// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "���춫·");
        set("long", @LONG
��Ȼ�ǵ��£������Ȼ����һЩ��ɫ���ԡ�·�߳���һ�ַ�ľ�ǲݵ�ֲ���
���Ǿ޴��Ģ��������������ɫ�Ĺ�â������һ���ر������ӵ�ֲ�Ҳ�ǻ���ɫ
�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ztdd",
  "south" : __DIR__"ntdm",
]));
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();

}