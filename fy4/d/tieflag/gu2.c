// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
С���ϣ������ʹ��������£���Ů��Ц��СϪ������������β��ɫ����Խˮ��
����
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gu1",
  "westdown" : __DIR__"gu3",
 
]));
	set("outdoors","tieflag"); 	 
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}

