inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ԭ");
        set("long", @LONG
Խ������ɽ����������ƽ̹����������أ������������ɳ�����ޱ��޼�
�ĸ�ԭ��������������ĿԶ���������ֹ�޾�������׳�ۣ��������ǡ��˵���紾
�ӣ������˿��Ե�·�ߵ�������ЪϢ�������������ó����̾ƿ���㡣
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"wild1",
		"northwest" : __DIR__"wild3",
		"southwest":  __DIR__"tent1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-1500);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}
