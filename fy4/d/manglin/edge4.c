inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "ç�ֱ�Ե");
        set("long", @LONG
Խ������Խ�ܣ�������������������Ҳ��ð߰ߵ�㡣é�ݽ��񣬹�ľ������
·�����𡣴����ķ�ҲԽ�������䳱ʪ��Զ�����ֵ�������м�ֻ������ͺӥ����
��˺���ѷεĽ���������ë����Ȼ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	  "north" : __DIR__"groups4",
	  "southup" : __DIR__"woodsroad",
	]));
        set("outdoors", "manglin");
	set("NONPC",1);
	set("coor/x",60);
	set("coor/y",-200);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
