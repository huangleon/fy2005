// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ����˾");
        set("long", @LONG
������˾���������һ������׵Ľ����������ϣ�������λ�ڽ���ʿ������Ʈ
Ʈ���ɷ���ǡ�
LONG
        );
        set("exits", ([
		"southeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/yuefei":1,
        ]) );
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
 
