// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���츣��");
  set("long",@LONG
���·ת����һʯ�����ڵ��ϣ������ĸ����֣����츣�ء���һ��������Լ
�ɼ���ɽ�紵����������ˬ�����˾���һ������ɽ����û������֮�У����ɼ�һ
����⡣
LONG
  );
  set("exits",([
         "westdown":__DIR__"qiyan.c",
         "northup" :__DIR__"chansi.c"
               ]));
        set("objects", ([
                __DIR__"npc/laoshi" : 1,
       ]) );
        set("outdoors", "qianfo");
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-10);
	setup();
  replace_program(ROOM);
}
