inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
�Ӷ��ɽ������ɽ����ɽ����Լһ����ʱ��·�̡�������ټ��Ĳ�ƺ��������
�ı������������ش�ɽ����һ��������һ��֮��������Ϫ��ת��ɽ�ǣ����治Զ��
��һ����ש���ߵ�ׯ԰����˵��һλ������������˽������ģ��ڴ����ӡ�
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"valley1",
		"southup":  __DIR__"haizi",
		"west": 	__DIR__"xuevillage",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2060);
        set("coor/y",580);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
