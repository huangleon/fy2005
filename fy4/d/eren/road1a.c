inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
������ɽ����һ��Сƽ�أ����ô����¼�����ʯ�ʣ��Ǹ���ɽ��Ъ��֮������
�����������嶥���ڰ��ƻ���֮������������һ�����������С·����ʯ����ʱ��
ʱ����Զ����������ש���ߣ��ƺ��Ǽ���ׯ԰��
LONG
        );
        set("exits", ([ 
		"eastdown" : __DIR__"road1",
		"westdown": __DIR__"road1b",
	]));
        set("objects", ([
        	__DIR__"npc/swordman1": 1,
        	__DIR__"npc/swordman2": 1,
        	__DIR__"obj/stonestool": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
