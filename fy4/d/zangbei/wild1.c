inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����ɽ��");
        set("long", @LONG
����ɽ����´��ɽ��������羰����������������[33m����ɽ[32m�����ɸ󡣾�˵ɽ
�ﻹס��һ���ˣ�����˰�������ס�ĵط�������������һƬ���ǡ��ڲ�ͬ�ļ���
�У��������в�ͬ�Ļ�ʢ����������ס�ڻ�������ʢ���Ǹ��ط���
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"yuzhu",
		"west" : __DIR__"wild2",
		"north": __DIR__"erlang",
		"south": __DIR__"mroom",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	
}
