// Room: dong1
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "ɽ϶��");
        set("long", @LONG
������ɭ������ֲ�����ָ���ּ���ʪ������һ��ͨ������ǰ����ȥ��ȴ��
֪�ж���Զ��
LONG
        );

       set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"dong0",
  "west" : __DIR__"gu",
 
]));
         
	set("coor/x",60);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}
