
inherit ROOM;

void create()
{
        set("short", "����ǰ");
        set("long", @LONG
����·�ԵĲݵأ����¹�����ֻ��·��һ�����ᣬ�����ڴ���֮�䣬΢�������
������ɡ���Զ�������������ɽ����һƬС�ɵ�¥�󣬷�����������������
������ʹ�һ�㡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"house2",
  "east" : __DIR__"bamboo",
  "north" : __DIR__"valley",
]));
        set("outdoors", "palace");

	set("coor/x",30);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

