inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
����Խ��ƽ̹������ǰ�߱���һƬ���֡��������������У�һ��һ������⣬
��������֦�����˵����Ƶģ����������������˵����ϣ�����ϸ��һ���泩��֦
ͷ������������æµ��׼��������ʳ�һ�����Ե����ӱ���Բ��
LONG
        );
        set("exits", ([ 
	"southup" : __DIR__"road3",
	"northdown" : __DIR__"road5",
	]));
        set("objects", ([
                	__DIR__"npc/songshu": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",40);
        set("coor/z",20);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
