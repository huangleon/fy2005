// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�ӹ�¥");
  set("long",@LONG
�����ǰ��÷��ӣ���ĵĵط������ڳ����ӣ�ĺ���ģ�����������������࣬
����ʾ�������е�ɮ�ڡ�
LONG
  );
  set("exits",([
            "westdown":__DIR__"weituo.c"
               ]));
          set("objects", ([
                __DIR__"npc/bonze7" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",10);
	setup();
  replace_program(ROOM);
}
