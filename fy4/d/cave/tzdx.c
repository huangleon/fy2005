// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit __DIR__"cave_mine";

void create()
{
        set("short", "���е���");
        set("long", @LONG
�����Ǹ�����·�ڣ�����Ĳ��ֱ��ͨ������������ģ�������Ϳ��Կ�����
�ĵ�԰̳���ڰ����ʱ�򻹿��Կ����Ӷ���Բ��ֱ��������Բ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btxl",
  "south" : __DIR__"ntxl",
  "east" : __DIR__"zdxm",
]));
        set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	
	setup();
}


