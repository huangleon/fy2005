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
  "west" : __DIR__"center1",
  "north" : __DIR__"dummy1",
  "south" : __DIR__"dummy1",

]));
        set("objects", ([
                __DIR__"npc/tiger" : 2,
                __DIR__"npc/wolf" : 1,
                __DIR__"npc/snake" : 1,
                __DIR__"npc/bear" : 1,
       ]) );
        set("outdoors", "manglin");
	set("coor/x",9);
	set("coor/y",0);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}
