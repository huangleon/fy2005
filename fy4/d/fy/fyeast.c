
inherit ROOM;

void create()
{
	set("short", "���ƶ� ");
	set("long", @LONG
·���������߶���һ���޼ʵ�ׯ�ڵء�˳��·����ǰ�ߣ�������
��ɽ��˳����ȥ���䵱ɽ�����ߣ�Ҳ���Ǻ���ΰ������ɽ����������
�͵Ĳ�ʱ¶��������ɫ���ݶ�������һ�������ĸо���
LONG
	);
	set("exits", ([ 
		"south" : "/u/wudang/bwuroad1",
		"north" : "/u/palace/palace_path1",
		"west" : __DIR__"sroad6",
	]));
	set("outdoors", "wudang");
	set("coor/x",300);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",300);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
