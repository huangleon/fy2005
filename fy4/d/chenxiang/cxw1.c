// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���������");
        set("long", @LONG
·��ϡϡ��������ż���Ҭ�������ڷ��л�ѽ�εأ��ƺ��ں�·�˲�ͣ�ش���
��������ĳ���̨���ַǷ����Ҳ���̯λ��������С������ɢ���������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farmershop",
  "west" : __DIR__"cxw2",
  "east" : __DIR__"cxcenter1",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
