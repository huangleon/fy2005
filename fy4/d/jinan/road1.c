// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","б����");
  set("long",@LONG
�ƹ������������������У�����һ������ʯ��·��������ɣ��ʯ�����ѿӿ�
���ݣ����Ծ��������������������ϻ�����һ�����������������·���س����У�
һƥ��������������������Զ���������಻�ϵ�ɽ�ͱ��Ƕ���̩ɽ�ˡ�
LONG
  );
  set("exits",([
         "southwest":__DIR__"lake",
         "northeast":__DIR__"road2",
               ]));
        set("objects", ([
                __DIR__"npc/sadguy" : 1,
                __DIR__"npc/shouma" : 1,
       ]) );
    set("outdoors", "jinan");
	set("coor/x",30);
	set("coor/y",100);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

