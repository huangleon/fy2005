// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ʯ��Ⱥ");
        set("long", @LONG
������һƬ��ʯ�����СС����ɫ������ǧ��ٹֵ���ʯ�������ʯ�����ƣ�
����������ֱ�������У�С��Ҳ������ʮ�ɣ���̫�ź��ʱ�Ķ������ޣ�������
�׾���������Ž�ȫ����㶼���ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"entrance",
  		"east" : __DIR__"road2",
	]));

        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
