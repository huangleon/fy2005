// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//mac's jiaolou4.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ßç½ÇÂ¥");
  set("long",@LONG
ÕâÊÇá·ÃíÎ§Ç½ËÄÓçµÄ½ÇÂ¥£¬·Ö±ğÒÔËÄØÔÎªÃû£¬ÒÔÇó±ÜĞ×Ç÷¼ª£¬Â¥ÖĞÓĞÒ»Ãæ´ó±®£¬
±®ÉÏÊéÒ»´ó×Ö£º
[33m
				ßç
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
