
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
		"south" : __DIR__"xiaozhen",
		"north" : __DIR__"bwuroad1",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",110);
	set("coor/z",-50);
	setup();
}
