inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�����");
        set("long", @LONG
��ǧ������Ҳ�Ҳ����ڶ������������ͥ԰��ͬʱ�������ҵ�����������˵�
�ط������ֲ�ͬ���ˣ��Ӹ��ֲ�ͬ�ĵط��������������ǲ�Ӭ���������ϵ�Ѫ����
�������ﻨ�������һ�����ӣ�Ҳ�������ԩ������Ϊ�����Ǹ��ϴ�ġ�����֡���
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"bridge",
		"northup":  __DIR__"mount3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1680);
        set("coor/y",610);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}
