// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
�����ϵͣ��������ؾ�������б��ľ�塣��������Գ��׵���ᵽ�ⶴ�ж��
�����¶�̫��ÿ����ʯ�߶�������࣬�ͺ�̨��һ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tnzl",
  "east" : __DIR__"dnm",
  "west" : __DIR__"xnm",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-14);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
