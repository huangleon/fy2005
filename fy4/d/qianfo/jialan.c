// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","٤����");
  set("long",@LONG
٤�����ڹ�������ػ�٤�����ص���������Ϊʩ����԰����ĸ��¶����ߣ�
����Ϊ����̫�ӣ��丸��˹�������ҡ�
LONG
  );
  set("exits",([
         "east":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                __DIR__"npc/bonze1":1,
       ]) );

	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
