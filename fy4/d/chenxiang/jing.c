// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
������̨�ף�������һ�ȣ�ո�µĴ���ֽ�����ż���˿��û��ĥ�𡣴�����
һ�۾Ϳ��Կ������ߵ������֣��������ϸһ��Ļ��������Կ��������е�Сͤ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxs6",
]));
        set("objects", ([
        __DIR__"npc/jadeowner": 1,
                        ]) );
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
