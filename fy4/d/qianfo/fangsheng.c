// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
��������ɽȪ�㼯���ɡ�Ȫˮ�峺���ף�������ɰ���ͷ������������������
���������ˮ���������ڵ��Σ����˶������⣬�����ڽ��������ɼ������˻�ȷ
�м��ֵ���
LONG
  );
  set("exits",([
         "east" :__DIR__"jinggang.c",
         "north":__DIR__"changlang.c",
               ]));
        set("outdoors", "qianfo");
        set("resource/water",1);
	set("liquid",([
            "name":"ɽȪˮ",
            "container":"������"]));
        set("objects", ([
                __DIR__"npc/lady" : 1,
		__DIR__"npc/badguy":1,
       ]) );

	set("coor/x",-10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

