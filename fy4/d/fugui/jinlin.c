inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǽ��˧ÿ������ЪϢ��һƬ���֣��Ĵ���Ӣ�ͷף���·��������ɾ���
��������һ�н�����Թ���ڴ�����һ����
LONG
	);
	set("type","forest");
	set("outdoors", "fugui");
	set("exits",([
		"southwest":__DIR__"jinshi",
		"northwest":__DIR__"jinmen",
	]) );

	set("objects",([
		__DIR__"npc/dashuai":1,
		__DIR__"npc/guard1c":1,
		__DIR__"npc/guard1b":1,
	]));
	set("coor/x",70);
	set("coor/y",50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
