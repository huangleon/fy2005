// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ؤ��ֶ�");
        set("long", @LONG
ֻ��ؤ��Ż������￪�ֶ棬���ܹ������������ͳ��������Ǻ�ؤ���в���
����Ĵ��ҲŻᵽ����������������������������������˾���������������
��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"cxw3",
]));
        set("objects", ([
        __DIR__"npc/gm": 1,
        __DIR__"npc/gaibang3": 1,
        __DIR__"npc/gaibang2": 1,
        __DIR__"npc/gaibang1": 1,            
                        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
