// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//mac's jiaolou4.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���¥");
  set("long",@LONG
�������Χǽ����Ľ�¥���ֱ�������Ϊ�����������������¥����һ��󱮣�
������һ���֣�
[33m
				��
[32m
LONG
  );
  	set("exits",([
         	"south":__DIR__"jiaolou2",
         	"west" :__DIR__"wangyue",
        ]));
        set("objects", ([
                	__DIR__"npc/gang4" : 1,
       	]) );
	set("coor/x",30);
	set("coor/y",20);
	set("coor/z",10);
	setup();
  	replace_program(ROOM);
}
