#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����ƽ��");
	set("long", @LONG
�߽��������ͬ�߽�����֮�С�������ˮ����㾪�ȵط��֣���Ȼ��һ
��СС���ٲ��Ӷ���к�����£����������л��СС��ˮ̶��ˮ̶�ߣ��и�âЬ
���ȵĲ��ˣ���������������������Ȼ���ҡ����е� ������âЬ��ʤ��˭�£�
һ��������ƽ������ ���⾳��
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/staffbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();
}

