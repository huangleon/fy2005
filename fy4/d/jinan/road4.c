// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
̩ɽ������ǰ�ˣ������������������ǵ����·�����������������ʯ����
�����۵ĵ���һ������ߵ�ͭ���������˵�ǵ������������̩ɽ������������
��ī���͵ġ���������ǧ��������
LONG
  );
  set("exits",([
         "southwest":__DIR__"road3",
         "northeast":AREA_DAIMIAO"shuanglong",
               ]));
    set("outdoors", "jinan");
	set("coor/x",270);
	set("coor/y",330);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

