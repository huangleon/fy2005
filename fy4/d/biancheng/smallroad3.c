inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ª��");
        set("long", @LONG
С�ﲻ���խ���η��ʱ���ɰ���죬�����ʱ����Ţ��·���������ᶼ��ƶ��
�˼ң����ű����С���������������������޴����ˣ����Ѽè������ʺ�������У�
�Ҽһ������ſڶ�ɹ��С���·����򲼡�
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"smallroad2",
	"south" : __DIR__"smallroad4",
	"west"	: __DIR__"cabin3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-50);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
