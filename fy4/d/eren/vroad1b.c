inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
��Ұ����ҹ������ϴ��ׯ�ڱ���ؾ���ͷ������ɫ��Ũ���̡����鳤�ø߹���
ͷ���ſ����ƴ��Ҷ�ӣ��������޻�һ�ȣ����Եø��Ƿ��󡣽�ƵĲ˻������̵�
�㶹���ۺ�������������ϵ����ӣ��ڲ��õ�������ҫ�����Ź⡣
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"vroad1",
	]));
        set("objects", ([

	]) );
	set("outdoors", "eren");
        set("coor/x",40);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
}
