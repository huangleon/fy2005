// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ���ŷ�");
        set("long", @LONG
����һ��ʯ���ŷ�������ʯ�ź󣬱��ǻ�ɽ����ʯ����ȥ��ֻ�������䣬��
��һƬ���̡�Ⱥ���������嶥�������ƣ����ɴ��ӭ������������·����һС
������������Ъ�š�
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"wenquan", 
  "north" : __DIR__"jiusi", 
  "east" : AREA_CHENXIANG"cxs1",
]));
        set("objects", ([
        __DIR__"npc/3cheng" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
