// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��˶�");
        set("long", @LONG
��������Ǿ����۵ף����۵��������������Ҭ��������ɫ�ĳ�ǽ�ͽ��ɫ
�������ݶ������ɼ���չ��Զ����һƬ��ѹѹ��ɭ�ֱ�һ�������������ţ��ͺ���
�������Ƶġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
        set("objects", ([
        __DIR__"npc/sb": 1,
                        ]) );
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
