
inherit ROOM;

void create()
{
	set("short", "�����ƺ�ǽ");
	set("long", @LONG
������ǽ��ɽ���������ת���ۡ��ߴ���أ�ʹ�����߽�ɽ�����ϸе�һ����
�����Ϻ�����ңԶ����˵������ʱ�ڴ˶��飬Ԣ�����޶��������ۼ�����
LONG
	);
	set("exits", ([
		"north" : __DIR__"qiongtaiguan",
		"southup" : __DIR__"sansongting",
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
