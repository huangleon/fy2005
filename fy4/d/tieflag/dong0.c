// Room: dong0
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "ɽ϶��");
        set("long", @LONG
����ɽ�ڼ�һ��һ�߶���ɽ϶���������ڱ��ϵ������������ڣ�������ϸ̽
����ѷ��֡�
LONG
        );

       set("exits", ([ /* sizeof() == 2 */
  		"east" : AREA_EASTCOAST"troad3",
  		"westdown" : __DIR__"dong1",
 
]));
         
	set("coor/x",70);
	set("coor/y",-10);
	set("coor/z",50);
	setup();
	replace_program(ROOM);

}

