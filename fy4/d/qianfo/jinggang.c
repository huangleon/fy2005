//mac's jinggang.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","��յ�");
  set("long",@LONG
������ʿִ����Ʒ������ҡ�������ò��ΰ������ŭ�࣬ͷ�����ڣ��ϰ����
�㣬�����ſ����ʽ���״������ŭ���ſڣ�����������֮�ƣ�������ձտڣ�ƽ��
����ƣ�ŭĿ���ӡ�
LONG
  );
  set("exits",([
         "south":__DIR__"chansi.c",
         "west" :__DIR__"fangsheng.c",
         "north":__DIR__"qianyuan.c",
         "east" :__DIR__"fudong.c"
               ]));
        set("objects", ([
                __DIR__"npc/lishi" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
