// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "�춫����");
        set("long", @LONG
·��ʪ��ǽҲ��ʪ������û�л�ˮ�����������������ˮ������������������
������������İ��Ӻܶ�����ݺύ��ˮ���ļ������������¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"twt",
  "east" : __DIR__"dbm",
]));
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();

}
