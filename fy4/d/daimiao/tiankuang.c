//mac's tiankuang.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ܵ�");
  set("long",@LONG
���ܵ�Ϊ�������Ϊ�ߴ�Ķ�����۲�������Χ�ڷ��������ʵ۾��м���
ʱ�õļ�������������ڶ���������Ϊ���ͱڻ���չʾ̩ɽ���Ѳʱ�ĺƴ��档
LONG
  );
  	set("exits",([
        	 "north":__DIR__"houqing",
         	 "south":__DIR__"zhengyuan",
         	 "east": __DIR__"dongci",
        ]));
        set("objects", ([
                __DIR__"npc/master_semi" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  
}

int valid_leave(object me, string dir)
{
	if (userp(me))
		REWARD_D->riddle_done(me,"�������",10,1);
	if (QUESTS_D->verify_quest(me,"�������"))
		QUESTS_D->special_reward(me,"�������");  
	return 1;
}
