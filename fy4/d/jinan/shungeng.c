// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","˴��ɽׯ");
  set("long",@LONG
����Ǻպ�������˴��ɽׯ��˴��ɽ�ֳ���ɽ����˵��˴�����ػ��ĳ���ء�
�����Ǽ��Ѳ��ö�֪��������ķ���ȷʵǧ���������ڴ���һ�������������һ
�����Ρ���ؤ����������֮�£���ʵ�Ǹ������£��ô�ϲ�������ΰ����Ϲ���һ��
ǧ���ڴ˽������ݻ���ؤ�����á�
LONG
  );
  	set("exits",([
         "east":__DIR__"street2",
         "north":__DIR__"gb1",
         "west":__DIR__"gb5",
               ]));
        set("valid_startroom", 1);
	set("coor/x",-20);
	set("coor/y",80);
	set("coor/z",0);
	setup();
        
}
