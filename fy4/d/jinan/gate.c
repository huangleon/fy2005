// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ϳǿ�");
  set("long",@LONG
������Ǽ��ϳǵ���ڣ����˼��ϳǣ�����������ǿ�ѧ֮�磬�����̱�һ��
ŨŨ����³���������������ϳǵĴ�������˳�֮Ϊ�׵������Ͽ����׸������֣�
�޴�������Բ�����Ŀ׼ҷ緶����Ⱦ����������ؤ�����ɰ����ÿ��ˡ�
LONG
  );
  set("exits",([
         "north"  :__DIR__"tanghuai.c",
		 "south" : __DIR__"street1",
               ]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",120);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

