inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ڰ���");
        set("long", @LONG
�����������ֲ�����ָ����ʲôҲ����������ֻ������ԼԼ����ǰ���д��ص�
��������һ��������Ĵ�վ��һֻС���ϡ�
LONG
        );
        set("exits", ([ 
		"south":	__DIR__"tunnel3",
	]));
        set("no_fly",1);
        set("item_desc", ([
      		
    	]));
        set("objects", ([
        	__DIR__"npc/sunju":	1,
        	__DIR__"obj/boat":	1,
	]) );

        set("coor/x",-1260);
        set("coor/y",990);
        set("coor/z",-60);
	set("map","zbeast");
	setup();
}
