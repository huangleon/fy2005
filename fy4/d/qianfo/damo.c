// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","��Ħ��");
  set("long",@LONG
����[33m��Ħ[32mΪ�й����ڵ�ʼ�棬����ɽ�����´��ڹ������ţ��������Ϊ����֮
�棬������ʦ�����ֳ����Ρ����﹩�����������λ��ɽ���ޡ�
LONG
  );
  set("exits",([
         "west":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                BOOKS"iron-cloth_20" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
