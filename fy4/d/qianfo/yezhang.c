#include <room.h>
inherit DOOR_ROOM;
void create()
{
  set("short","Ү����");
  set("long",@LONG
��ӵ������֮���Ϊ�������ɵľ������˹����������ڵĵմ�����ʼ�����
�������������ĵ�����ӣ��˺��˲ű���������һ��С�ţ�û�з��ɵ�������
���˲������롣
LONG
  );
  	set("exits",([
         "south":__DIR__"houyuan.c",
         "north":__DIR__"mishi1.c",
         "east" :__DIR__"chanfang2.c",
         "west" :__DIR__"chanfang.c"
               ]));
          set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
 	set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  	create_door("north","door","ʯ��","south",DOOR_CLOSED);
}
