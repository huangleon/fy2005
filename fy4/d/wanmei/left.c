// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��Ū��");
        set("long", @LONG
һ�ߵ�ǽ�ϲ��������٣���׺��С�����ܶ����ߡ��պ�ʹ����͸�����������
÷�á������̵����Ϻõĺ�ש����ש����һ˿˿��̦�����ŷ���ÿ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"frontyard",
  "southeast" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/cat": 1,
	__DIR__"npc/ass": 2,
                        ]) );

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
