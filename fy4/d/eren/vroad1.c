inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ������");
        set("long", @LONG
��·���ԣ����з��ᣬÿһ���ݣ�����ü����ɡ�����Ҳ���������������ũ
�򣬰�̯��С����ż�����ܼ�������С���ڻ���׷�𣬰��ż���������Ȯ�͡�һ��
��ɨ�øɸɾ�������ʯС·ͨ��ɽ�����ġ�
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"valley1",
	"east" : __DIR__"vroad2",
	"south" : __DIR__"vroad1a",
	"north" : __DIR__"vroad1b",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",40);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
