#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����һ���徻���ŵ�С�ݣ����������������еĵط���ǽ������������Ļ�
����������Ϊ��һ���Ħ������ۿɣ�����ɮ貣�������ţ�������̣������
�ܣ�͸���������Կ�����ǰ��÷����
LONG
  );
  set("exits",([
         "northeast":__DIR__"houshan.c",
         "south":__DIR__"changlang3.c",
         "east" : __DIR__"yezhang.c"
               ]));
          set("objects", ([
                __DIR__"npc/bigmonk1" : 1,
                __DIR__"npc/bigmonk2" : 1,
                __DIR__"npc/bigmonk3" : 1,
        		__DIR__"npc/bigmonk4" : 1,
        		__DIR__"npc/bigmonk5" : 1,
        		__DIR__"npc/bigmonk6" : 1,
        		__DIR__"npc/bigmonk7" : 1,
        		__DIR__"npc/bigmonk8" : 1,	
       ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
