inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ���");
        set("long", @LONG
������ʯС·��ǰ�ߣ�·�Ե�����Խ��Խ�࣬�����ѿ쵽ɽ������ġ����׵�
���Ŵ󿪣��������оƲ˵���ζ͸�����߳����˸����͹�������ű��ö���������
�����µĶ���С¥�����ɫ�����������չ����������⣬������д���ĸ����ɷ���
�Ĵ��֡�������ջ�����Ա߻�����һ���������
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad1",
	"east" : __DIR__"vroad2a",
	"north" : __DIR__"jiaojiao1",
	"south" : __DIR__"hahalou1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",50);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
