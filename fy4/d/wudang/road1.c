
inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
·���������߶���һ���޼ʵ�ׯ�ڵء�˳��·����ǰ�ߣ������䵱ɽ��˳����
ȥ���䵱ɽ�����ߣ�Ҳ���Ǻ���ΰ������ɽ�����������͵Ĳ�ʱ¶��������ɫ����
��������һ���������µĸо���
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"xzroad3",
		"south" : __DIR__"gate",
		"west" : __DIR__"farm1",
		"east" : __DIR__"farm2",
	]));
        set("NONPC",1);
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",60);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}
