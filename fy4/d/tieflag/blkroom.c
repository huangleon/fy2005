#include <room.h>  
inherit ROOM;
void create()
{
  set("short","ʯ��");
  set("long",@LONG
��ֻ��һ�������ߵ�ʯ����ʯ����ͷ��һƬ�ز�������ˮ����������Լ������
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
  	set("exits/north"  ,__DIR__"outboat");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
 }
