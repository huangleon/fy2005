//mac's changlang.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
��ľ�������ѱ���ͺ��������ķ������ȼ������о�������˫�ﳯĵ����ͼ
���ľ����Ͻ�������������˻��ɴ�����������һ����С�
LONG
  );
  set("exits",([
         "east" :__DIR__"qianyuan.c",
         "south":__DIR__"fangsheng.c",
               ]));
        set("objects", ([
                __DIR__"npc/monk" : 2,
       ]) );
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
