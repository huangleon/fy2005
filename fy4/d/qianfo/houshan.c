//mac's houshan.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","��ɽƽ��");
  set("long",@LONG
������һ�鿪��ƽ�أ��ڴ�ɽ�ϱ�֮�У��������λ��ƣ���������ɮ����ϰ��
�ĵط������Ϸ�����������õ���е��
LONG
  );
  set("exits",([
         "southwest": __DIR__"chanfang.c",
         "southeast": __DIR__"chanfang2.c",
               ]));
          set("objects", ([
                __DIR__"obj/bigstone" : 1,
       ]) );
  set("outdoors","qianfo"); 
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
