// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�ϱ���");
        set("long", @LONG
����ɫ��ʯש����������Ľֵ������ƺ������Կ�������С���Ӱ�ӡ�����
һ�ж���ó¾����⣬���ʲô��û�б䡣�������ҩ���Ѿ�������ȣ�����õ�
�����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"cx2",
  "southeast" : __DIR__"cx4",
  "west" : __DIR__"yao",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
