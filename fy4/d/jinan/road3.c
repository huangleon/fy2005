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
         "south":__DIR__"road",
  "northeast" : __DIR__"road4",
               ]));
	set("outdoors", "jinan");
	set("coor/x",70);
	set("coor/y",180);
	set("coor/z",0);
	setup();

}
