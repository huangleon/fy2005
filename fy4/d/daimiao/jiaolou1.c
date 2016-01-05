//mac's jiaolou1.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","À¤½ÇÂ¥");
  	set("long",@LONG
ÕâÊÇá·ÃíÎ§Ç½ËÄÓçµÄ½ÇÂ¥£¬·Ö±ğÒÔËÄØÔÎªÃû£¬ÒÔÇó±ÜĞ×Ç÷¼ª£¬Â¥ÖĞÓĞÒ»Ãæ´ó±®£¬
±®ÉÏÊéÒ»´ó×Ö£º
[33m
				À¤
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
