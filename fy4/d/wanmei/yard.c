// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ɽׯ��Ժ");
        set("long", @LONG
��Ժ��ǰ����ׯ����͵�ѩ÷����һ�����ǿ�÷�õĺ��š�ɽ�紩�ö�����
��÷�õİ���������ѩ÷�󡣸�ǰ����ʯ�ײ����˸�ɫ�Ļ��ꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"meidang",
  "southwest" : __DIR__"right",
  "northwest" : __DIR__"left",
  "east" : __DIR__"center",
  "north" : __DIR__"cleft",
  "south" : __DIR__"cright",
]));
        set("outdoors", "wanmei");

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
