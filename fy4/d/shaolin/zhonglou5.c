// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
������������������ϵķ���ֻ��һ�㣬�������ϣ�¥�ݹ�����
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou6",
  "down" : __DIR__"zhonglou4",
]));
		        set("objects", ([
                __DIR__"npc/monk5_sentry" : 1,
                __DIR__"npc/monk51_sentry" : 1,	   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
