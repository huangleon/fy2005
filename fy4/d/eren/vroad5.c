inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ�����ͷ");
        set("long", @LONG
����ǰ�Ϳ�����ˣ���ʯ·���˶�ֹ������עĿ����·�ԵĲݵ�����һ������
�ߵ�������һ���ִ�ŵ���׺��ӣ�������ī���Ũü�������ȧ�ǣ�һֻ�ݹ�
��᾵Ĵ���ץ�ű�����ÿ��õ�������
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad4",
	"northwest" : __DIR__"groad5",
	"southeast":  __DIR__"waterfall",
	"east": __DIR__"orchard1",
	]));
        set("objects", ([
        	__DIR__"obj/statue":1,
	]) );
	set("outdoors", "eren");
        set("coor/x",100);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
}
