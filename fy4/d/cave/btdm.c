// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "���춫��");
        set("long", @LONG
����Ķ���ͻȻ������࣬�ͺ���һ����Ȼ���ݶ����ݶ���һ�����ܵ�����ʯ
֧���ţ��γ�һ��ǽ����ǽ���м�����һ�ɶ��Ŀ�϶���պ�����ʯ�����̹���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbj",
  "south" : __DIR__"btdl",
]));
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",5);
	set("coor/z",0);
        setup();

}
