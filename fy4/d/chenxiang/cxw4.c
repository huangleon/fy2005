// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С����");
        set("long", @LONG
��ɲ�����ԭ����ʩ������ˮ������ɫ������Ư���Ÿ��ָ�����������ż����
��һ���������ݸ������棬��������ཹ�ཡ���������������Ǽ�����ס��������
�Ļᱻ����ĳ���Ѭ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxw3",
]));
        set("objects", ([
        __DIR__"npc/qingbo": 1,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",-40);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
