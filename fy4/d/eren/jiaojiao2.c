inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ͷ�");
        set("long", @LONG
������ջ�Ŀͷ���һ�׺�ɼľ�ļҾߣ�һ�����߿�Ĵ󴲡����ڴ�ɨ�ĸɸɾ�
����ױ̨��һ����ƿ�����һ���²ɵ�Ұ�軨���ߵ�����������ȥ�����ƴ�������
������ũ������������
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"jiaojiao1",
	]));
        set("objects", ([
        	__DIR__"obj/vase": 1,
	]) );
	set("coor/x",50);
        set("coor/y",70);
        set("coor/z",10);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
