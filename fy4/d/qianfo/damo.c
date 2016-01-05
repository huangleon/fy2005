// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","´ïÄ¦ÌÃ");
  set("long",@LONG
ÆĞÌá[33m´ïÄ¦[32mÎªÖĞ¹úìø×ÚµÄÊ¼×æ£¬ÓÚáÔÉ½ÉÙÁÖËÂ´´±Ú¹ÛÆÅÂŞÃÅ£¬Áù×æ»ÛÄÜÎªìøµÀÖ®
×æ£¬°ÙÕÉìøÊ¦½¨´ÔÁÖ³ÉÆäĞÎ¡£ÕâÀï¹©·îµÄÕıÊÇÕâÈıÎ»¿ªÉ½×ğËŞ¡£
LONG
  );
  set("exits",([
         "west":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                BOOKS"iron-cloth_20" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
