inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����СԺ");
        set("long", @LONG
һ��СС�����ӣ���ɫǽ����ɫ���ݶ�������úܾ��¡��������и�СС�Ļ�
�ԣ��м��仨��ʢ����ȴ�������ǲ軨���Ǿջ���һ��СϪ�����ش���ǰ�ʹ�����
����������Ҳ�������ˣ�������·���յ�µƻ�δϨ��	
LONG
    );
        set("exits", ([ 
		"enter": __DIR__"star_room1",
		"east":  __DIR__"river",
	]));
        set("objects", ([
        	
	]) );
        set("coor/x",-1680);
        set("coor/y",640);
        set("coor/z",0);
        set("no_fly",1);
		set("map","zbwest");
	setup();

}
