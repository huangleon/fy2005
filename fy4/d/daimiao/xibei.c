//mac's xibei.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
��Ϊ�����ʵ۾��з������ʱ�ı��̣�������עĿ�����ض���̩ɽ��ʯ��Ϊ��
Ԫǰ��������ض�����������̩ɽʱ����ة����˹��̵ģ���ϧ����ʮ�����֣���
˹ȥ�����������ӳ���
LONG
  );
  	set("exits",([
         	"east":__DIR__"zhengyuan",
         	"west": __DIR__"w_bei",
               ]));
   
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
