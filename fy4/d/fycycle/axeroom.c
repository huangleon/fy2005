#include <room.h>
inherit ROOM;
void create()
{
	set("short", "���ٺ���");
	set("long", @LONG
���е�һ�к����������������������ƺ����ϴ��������������ɫ�ĵ���
�·�Ҳ��ĳ�����ض�������Һ�塣����ϸ�д�֮�£�ȴֻ�����޾�ֹ�Ŀռ����
ʵ�ȶ��ĵ��档�ָ������ߵģ���һ����׾�Ŀ��츫����Ƕ�����е�ǽ�ڣ��ƺ�
��һ��֮�·ֿ�����������Ľ��ߡ�
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/axebook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();
}

