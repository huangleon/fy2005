inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ǰԺ");
        set("long", @LONG
һƬ��Ŀճ���������ũ���ķ��ݣ�������ׯ����լ�ӣ�լ�ӵ�����������һ
��߸ߵ�԰ǽ��ǽ����һ��һ�ŵķ�ï�İ�ɼ���м���һ�����ֱ·��˳������·
�߹�ȥ������Խ��������õ���������Զ�����������ޱ��޼ʵĲݳ���
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"yard2",
		"out" : __DIR__"gate",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",90);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
