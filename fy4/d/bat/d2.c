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
		"north" : __FILE__,
        "south" : __FILE__,
        "west" : __DIR__"d3",
	]));
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
