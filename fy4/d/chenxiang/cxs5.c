// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
�뿪����ǵ������Ѿ���һ�ξ����ˣ���Ȼ����������Զ��������������ÿ��
΢�������Ҭ�����������������ɳɳ���ͽ�����С����û�������Ͼ���һƬС��
�֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs4",
  "west" : __DIR__"mudan",
  "east" : __DIR__"suren",
  "south" : __DIR__"cxs6",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
