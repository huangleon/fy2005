// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ի��");
  set("long",@LONG
ի��Ϊ����ɮ�ڳԷ��ĵط�������ͷ®�����񣬴�˵��ɮ������ע���ۣ�ҹ��
�μ���ɮ��ͷ®Ȱ����  ի�ã����Ǵ���֮����ի���Թ�֮��
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang3.c",
            "east" :__DIR__"guanyin.c",
            "west" :__DIR__"zt2.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
