// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <room.h>
void create()
{
	object con, item; 
  set("short","ؤ��˽��");
  set("long",@LONG
������ؤ���˽��������ǽ�Ϲҵ���һ������Ļ��һ���Ϻ�ף���������һ��
����ͼ���ݳƶ�����Ʒ�����˾��Ѿ���ֵ���ǡ�������˵�ⷿ��İ����ˡ�
LONG
  );
  set("exits",([
         "south":__DIR__"gb4",
               ]));
	set("objects", ([
	    __DIR__"npc/master5" : 1,
	]) );
	set("have_staff", 1);
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",0);
	setup();

}
