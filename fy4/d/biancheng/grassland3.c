inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���ԭ");
        set("long", @LONG
�����õĵؽ磬�Զ������������ÿ����ۣ����峿������ҲҪ���ƻ���ߵ�
��ȫ�̡�ԶԶ����ȥ��һ���ɫ�Ĵ������ڷ�ɳ�зɾ���������Զ����ߡ�����
����ҲԶ����ߣ��ޱ��޼ʵĻ�ԭ��·������̤�����ģ���������ֱ����ֱͨ����
����졣���¾��������á�
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"grassland2",
		"east" : __DIR__"grassland4",
		"northwest":	__DIR__"gate",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",100);
        set("coor/y",80);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
