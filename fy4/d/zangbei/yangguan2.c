inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��Į");
        set("long", @LONG
ããһƬѩ�ף�ʲôҲû�У���һ������Ҳ�Ҳ�����û�бߣ�û�мʡ���߽�
��Ʈ�������̼�����������ȴ�ڼ���ɻ���Σ��ŷ��֣����Ǹոջ�ѩ��ɽ����
ż����ƽ���ϻ��м�����Ӱ�����ǰ�������á�
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"kunlun1",
		"southeast" : __DIR__"yangguan1",
		"south" : __DIR__"yangguan1a",
		"east" : __DIR__"yangguan1b",
	]));
        set("objects", ([
        	        __DIR__"npc/traveler" : 2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-300);
        set("coor/y",300);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}
