// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������·");
        set("long", @LONG
���ߵĽ����ߴ���Ұ��࣬��ס�˴󲿷ֵ���պ����е����⡣�����ٺõ���
����Ҳ��һ�ɷ�ù��ζ����·�ߵĿ��ݻ����˶������ˮ��һ��С�ľͻὦһ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gaij",
  "south" : __DIR__"yongj",
  "west" : __DIR__"cxw4",
  "east" : __DIR__"cxw2",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
