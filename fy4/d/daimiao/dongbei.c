//mac's dongbei.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
��Ϊ̩��������ǵı��ȣ������������Ƹ��ں�����������������ǲ��ʿ����
�浽̩ɽ��������ʱ������˫���������ԧ�챮��������������ͬ��ʯ�������ɣ�
�����������ڲ���������ͬ�����¡�
LONG
  );
  	set("exits",([
         	"west":__DIR__"zhengyuan",
         	"east": __DIR__"e_bei",
               ]));
        set("objects", ([
        
       	]) );
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
