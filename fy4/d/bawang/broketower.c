inherit ROOM;

void create()
{
	set("short", "�����ײ�");

	set("long", @LONG
���Ƕ�����һ�㡣���������ҳ���һ��������ķ��⣬�����ƺ�ʲô��û�С�
���洰���Ϻ�����ֽ�Ѳ����ˣ����紵�á����������������졣Խ�ߵ����棬��Խ
������Խ�죬�����Ҳ����Խ�졣�����ߵ�ľ�ݸ����ưܣ��ƺ���ʱ�����䡣
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"broketower2",
		"out":__DIR__"undertower",
	]) );

	set("objects", ([
		__DIR__"npc/ghost": 3,
	]));
	setup();
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",-10);
	replace_program(ROOM);
}
