// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
����Խ��Խ�ӣ���ֱ���ڿ��ȣ�������ɽ�ȣ������ѱ��һ�ɺ�¯��Ҫ������
�ǵ���ꡣ����ǰ�棬ɽ���л�Ȼ���ʣ�Ⱥ��ϱ��䣬����һƬ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"flower",
  		"north" : __DIR__"flower2",
	]));
	set("no_force",1);
	set("no_fly",1);
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
