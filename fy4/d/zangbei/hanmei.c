inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��÷��");
        set("long", @LONG
��÷���Ǻ���ɽ���ߵ�ɽϪС����ȫ������ʮ������Ǹ�������ɽ�ȣ����
��������ѩ���ף�÷���ʺ졣ɽ�ȵ�һ�����ż������Ž����Ľ��¹��ӣ��ƺ�����
��ѩ����ֵ��ǣ�������һ�����߿������߳߳��Ŀӣ��ӱ߷������Σ�����
��ʳ�У�������̳�ơ�
LONG
        );
        set("exits", ([ 
		"westup" : __DIR__"haizi",
	]));
        set("objects", ([
        	__DIR__"npc/qiu":	1,
        	__DIR__"npc/du":	1,
        	__DIR__"obj/hole":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2050);
        set("coor/y",560);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
