// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�챱����");
        set("long", @LONG
·�ߵ�ʯͷ�Ͽ���һ����ӬͷС�֣������������ʴ�Ѿ�����������д����ʲ
ô�ˡ�����ܹŹ�,�ƺ���������������,����ԼԼ���ƺ��м����ֿ��Ա��ϳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tbzl",
  "south" : __DIR__"tt",
]));
        set("objects", ([
        __DIR__"obj/fanstone": 1,
                        ]) );

        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-2);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
        replace_program(ROOM);
}
