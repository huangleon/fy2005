//mac's houzai.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
���ı��ŽС����ء�����˼�Ǵ�����ؾŻ�֮�£��ֳơ�³հ����ȡ���ڡ�
ʫ����³�̡��ġ�̩ɽ���ң�³����հ��������������¥���䣬�������������š�
�Ҷ�����Ǹ����ɵ���שΧǽ���򱱱���̩ɽ�ˡ�
LONG
  );
  	set("exits",([
         	"north":AREA_TAISHAN"daizong.c",
         	"south":__DIR__"tongting.c",
         	"up"	: __DIR__"wangyue",
         	"east": __DIR__"e_wall_4",
         	"west": __DIR__"w_wall_4",
        ]));
        set("objects", ([
		__DIR__"npc/guard2":	2,
       ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
