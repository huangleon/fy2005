inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��Į");
        set("long", @LONG
����ǰ�ߣ�ɳĮ�ޱ��޼ʣ�����ããһƬѩ��ʲôҲû�У���һ������Ҳ�Ҳ�
����Զ����������Ⱥɽ��������ѩ����������ֱ����ʡ�������������ж�����
���ߣ�٪��Ҳ����˾��ˣ�������������ж��������ߣ�����Ҳ�����٪�塣
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"yangguan2",
		"southeast" : __DIR__"yangguan",
		"west" : __DIR__"yangguan1a",
		"north" : __DIR__"yangguan1b",
	]));
        set("objects", ([
        	
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-100);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}
