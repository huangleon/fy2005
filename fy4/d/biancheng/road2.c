inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
��������������������С�ǣ�ÿһ�����������ӣ���ª�ķ��ݣ����۵Ļ��
�������˼ҡ�С�ǽֵ�������Ҳ����վ�ڽ��ľͿ��������ϱ����˵ľ�ͷ���紵
�������Ե�ľ�����ƻ������졣С�Ƿ·����һ��ճ�������׳��ҵ����飬��Ƕ��
�ޱ��޼ʵ�ԭҰ�
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road1",
		"west" : __DIR__"road3",
		"north": __DIR__"nstreet1",
		"south": __DIR__"sstreet1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
