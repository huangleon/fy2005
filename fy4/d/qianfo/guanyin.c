// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
���������ǹ������������ֳ���֦ˮƿ����ʨ����������٤ɽ��֮�䣬��
��������Э�ţ�������Ϊ������������ʨΪ��������������ΧΪ�����Ҿ����Ʋ���
ʮ���Ρ�
LONG
  );
  set("exits",([
            "south":__DIR__"weituo.c",
            "north":__DIR__"luohan.c",
            "west" :__DIR__"zhaitang.c",
            "east" :__DIR__"xiangji.c"
               ]));
          set("objects", ([
                __DIR__"npc/bonze8" : 1,
       ]) );
	set("NONPC",1);   
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
