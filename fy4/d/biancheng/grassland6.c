inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ݳ�");
        set("long", @LONG
�����Ĵ��ԭ�ϣ��滺����Ĳݵأ����ض��������̵���֮��ͷ���ݵ�������
�����ĺ������Ӱ��ߴ��������Ĳ�ʽ����ͬ���һ����ʫ���εĻ��档ÿ���峿��
��׵�Ũ�������ڵ������ʣ�ԶԶ������������ͬ���е�С������������һƬ��
�������ɽ�¡�
LONG
        );
        set("exits", ([ 
		"south":		__DIR__"grassland5",
		"northup":		__DIR__"hill",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",110);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
