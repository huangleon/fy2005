inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "ç��֮��");
        set("long", @LONG
���ܹ������죬�����ܲ���Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ�����ҹ��
��������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������Х�Ǻ������ȷ�
Ʈ�����ʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"center2",
  "north" : __DIR__"dummy2",
  "south" : __DIR__"dummy2",

]));
        set("outdoors", "manglin");
	set("coor/x",61);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
replace_program(ROOM);

}
