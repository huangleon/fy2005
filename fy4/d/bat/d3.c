// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "�ڰ�ɽ��");
	set("long", @LONG
����һ����ɭ�ɲ����������޹��ɽ����һ�߽������㵹����һ������������
һ����ѣ����ʲôҲ�벻�����ˡ�
LONG
	);
	set("exits", ([
		"east" : __FILE__,
        "north" : __DIR__"d4",
        "south" : __FILE__,
		"west" : __FILE__,
	]));
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
