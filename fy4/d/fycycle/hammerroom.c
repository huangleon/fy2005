#include <room.h>
inherit ROOM;
void create()
{
	set("short", "���˷�ɳ");
	set("long", @LONG
��һ�߽������ӣ����ﲻ��һ����ӭ�澹Ȼ��һ��ŭĿԲ�����뷢��ŵ�׳
ʿ��ֻ��������޴��������һ��ԾԾ���������ӡ�ϸ��֮�£�ԭ����һ������
���񡣷����ıھ��Ի�ɳͿǶ�������У����ٲ�����һ��֮����ֻ��ɱ���
���ݶ�����
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/hammerbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

