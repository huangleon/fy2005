#include <room.h>
inherit ROOM;
void create()
{
  set("short","��Ժ");
  set("long",@LONG
����һ���徻��СԺ��������໨����ľ����������ֻ����涷�޵Ŀ��ţ���
ʹ����Ҳ�а�ѩ�ĺ�÷��������˵���յ��������յľջ���Ժ�ı�����������Ү��
�ҡ�
LONG
  );
  set("exits",([
         "east" :__DIR__"changlang4.c",
         "west" :__DIR__"changlang3.c",
         "north":__DIR__"yezhang.c"
               ]));
   
	set("coor/x",1);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
