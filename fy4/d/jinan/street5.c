// street5.c

#include <room.h>
inherit ROOM;
void create()
{
   set("short","��ͻ��");
  set("long",@LONG
���Ϻų�Ȫ�ǣ���˵��Ȫˮ��ʮ��������ͻȪȺ�����бȽϴ��һ��ȪˮȺ�䡣
����Ȫˮ��ɺ�������Ȫ��·���γ���ˮ������������ò����ͻȪ�㼯�ɺӣ�����
��������������ͻ�š�Զ��ɽɫ�����鶯������ˮ�����ԣ��Ƶ�����³���ϡ�����
�����޽��Ĺ�ۡ���ţ����Ϸ����ǹ�Ѻ����֮�ء�
LONG
  );
    set("exits",([
        "north":__DIR__"street4",
        "south":__DIR__"govern",
        "southeast" : __DIR__"dayu",
    ]));
        set("objects", ([
        __DIR__"npc/yayi3" : 2,
        ]) );
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

