inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
����ѩɽ��С·��Ϊ��ʥ�ߵĽ�ӡ��ÿ�����Ϧ���г�ʥ����������Ӱ��ʵ��
����翡�����ƣ��һ�������ϸϸ�سԲݣ�ƣ��һ������Ҳ��ѩ���µ�������
��ȼ���������̡��ٹ�һ��������㷹������ʥ�ߺ����ĸ������ڳ���Ŀ�����
�뵿�����
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"echu",
		"southwest":  __DIR__"valley2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2040);
        set("coor/y",600);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
