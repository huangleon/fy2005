// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��·��������ƬСС�����֣���������һ��СС����ͤ����ͤ�Ķ����ϳ���һ
����ɫ��ϸ�񡣾�˵����ͤ�ǵ����������ʱЪ���ŵĵط�����������Ҳ�ǻ�����
�����µġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs5",
  "west" : __DIR__"jing",
  "east" : __DIR__"wol",
  "south" : __DIR__"cxs7",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
