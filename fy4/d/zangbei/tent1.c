inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
·��ż�����м������񣬻�δ�߽����������ξ޴���С�ܵĲ������ӭ�����ˡ�
��������ţë֯�ɣ����ؽ�ʵ����ţë������˩���ڵ��ϣ�����ס���ԭ�ĺ����
��ɳ������������ˣ���Զ�����Ŀ��˴����ǲ����ĵģ����Ͳ衢���κ�ţ���⣬
�ſ����ӳ԰ɡ�
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"wild2",
	]));
        set("objects", ([
        	__DIR__"npc/dawa":	1,
        	__DIR__"npc/wolfdog":	1,
	]) );
        set("coor/x",-1510);
        set("coor/y",690);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

