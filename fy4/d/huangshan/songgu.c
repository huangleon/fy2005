// mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�ɹ���");
        set("long", @LONG
��ǽ���ߵ�СԺ������������֮�У�һ��СϪ�����ִ�������СԺ�����ƹ���
����΢�����������֡��ɹ��֡���������㣬��Ȼ����Ů��֮�֣�������ľ������ʱ
�����ڴ�����͸���ŷ���Կ���Ժ����ֲ�Ļ��ݡ�
LONG
        );
	set("exits", ([ 
    	"south" : __DIR__"yard",  
		"north" : __DIR__"sroad",
	]));
     set("objects", ([
            "/obj/specials/ding/ding_hs" : 1,

        ]) );
    set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-35);
	set("coor/z",30);
	setup();
}



