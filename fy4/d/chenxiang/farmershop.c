// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ũ�ߵ�");
        set("long", @LONG
ǽ�Ϲ��Ÿ�ʽ������ũ����Ʒ��ÿ���������չ���ľ������죬�������Ϻõ�
ľ���������ǿ���ʯͷ�ϣ���Ҳ���������Ҳ����ϡ�һ�Ű���ɫ�Ĺ�̨�������
���м䣬��̨�ϻ����ż��������Ե��е�ľ�顣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"cxw1",
]));
        set("objects", ([
        __DIR__"npc/farmowner": 1,
	__DIR__"npc/haojie1": 1,
	__DIR__"npc/haojie": 1,
                        ]) );
	set("coor/x",-10);
	set("coor/y",-15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
