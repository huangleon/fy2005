inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "С����");
        set("long", @LONG
�ƿ���һ���ţ����Ǽ�СС�ĳ������Դ�����ǰ���㴨�ķ���������������
��ÿ�춼���ڰ�ҹ������Ū�㶫���ԡ���ϲ���Լ����֣�Ҳ��ֻ���ڳ������ʱ��
���Ż�����������ɡ�����ϲ�������ֲ��ǵ��������缦���㳦��
LONG
        );
        set("exits", ([ 
		"east": 	__DIR__"groom3",

	]));
        set("objects", ([
               	
	]) );
        set("coor/x",-1290);
        set("coor/y",980);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}
