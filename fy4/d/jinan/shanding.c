// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","ɽ�¶�");
  set("long",@LONG
������Ұ��Ȼ���������������ξ�����ǰ��һ��ƽԭ�ϻ�ս���ź��������
�ĺ��ź��ξ���ս�Ľ��ӣ����������һλ�������ף�����Ʈ����ӧ�����꽫����
��ע������ǰ��ս�֡�
LONG
  );
	set("exits",([
		"northdown" : __DIR__"shanpo",
    ]));
	set("objects", ([
		__DIR__"npc/yue" : 1,
	]));
//    set("valid_startroom",1);
    set("outdoors", "dreamland");
	set("no_fight", 1);
	set("no_magic", 1);
	setup();
}
