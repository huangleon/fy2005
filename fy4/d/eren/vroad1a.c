inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
��·���������߲ˣ���ƵĲ˻������̵��㶹���ۺ�������������ϵ����ӣ�
һ�ɷ��վ��󡣼���ũ��æ���ڵ�����棬�﹡�ϣ����������˦�Ź��Ѿ����Ϸ
׷�򣬺���һ����ڹ������ظ����ܡ�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"vroad1",
	]));
        set("objects", ([
		__DIR__"npc/sadkid": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",40);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
}
