//mac's jiaolou1.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","����¥");
  	set("long",@LONG
�������Χǽ����Ľ�¥���ֱ�������Ϊ�����������������¥����һ��󱮣�
������һ���֣�
[33m
				��
[32m
LONG
  );
  	set("exits",([
         	"down":__DIR__"jianda",
         	"east": __DIR__"wufenglou",
         	"north": __DIR__"jiaolou3",
        ]));
   
        set("objects", ([
        	__DIR__"npc/gang1":	1,
       	]) );
	set("coor/x",-30);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
  	replace_program(ROOM);
}
