// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
�߳�ɽ���������ǰ��Ȼ���ʡ�Ȫˮ���ˣ����񻶳���ʱ��ʱ����Ů��Ц����
�˹�������������ʯ��ǰ��һ��Ƭ���̵Ĳݵأ���������಻֪���Ļ��ݡ�����
���������������泩����е�������������Դһ�㡣
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gu0",
  "east" : __DIR__"dong1",
 
])); 

	set("outdoors","tieflag"); 		
         
	set("coor/x",50);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}

