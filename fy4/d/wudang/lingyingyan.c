
inherit ROOM;

void create()
{
	set("short", "��Ӧ��");
	set("long", @LONG
������������ɽ��С���������Ӧ���ٷ塱���׳ơ�����������ÿ��Ķ�������
�������������ƣ������Ը߲��ɲ�ĸо���
LONG
	);
	set("exits", ([
		"south" : __DIR__"wuroad3",
	]));
	set("outdoors", "wudang");
	set("objects", ([
                __DIR__"npc/taoist4" : 1,
                __DIR__"npc/taoist_1" : 1,
        ]));
	set("coor/x",30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
