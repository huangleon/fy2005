// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ǧ��ɽ��");
  set("long",@LONG
ǧ��ɽ��������ɽ�����й������ɽ֮һ���Ӵ���������һ����ɽ��������
�������Ӳ�����ɽ������Լ�ɼ������߷��������ɴ�ص���ӳ�¸��ⳬ�����ס���
����һ�����ش�������������������˴��ɽ��
LONG
  );
  set("exits",([
         "east" :__DIR__"tanghuai.c",
         "west" :__DIR__"road1q.c"
               ]));
        set("objects", ([
                AREA_QIANFO"npc/bonze" : 1,
       ]) );
        set("outdoors", "jinan");
	set("coor/x",-10);
	set("coor/y",130);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
