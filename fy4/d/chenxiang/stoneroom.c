inherit ROOM;

void create()
{
	set("short", "ʯ��");

	set("long", @LONG
���ߺ��ʯ�����һ��ų߿��ʯ���ӡ�������ɭ�����䣬�·��ѵ��˹Ŵ�
������Ĺ�����ġ�����Ӧ��ͣ�Źײĵĵط�������ȴ���Ÿ��޴�����䣬����֮��
ʲôҲû�С�
LONG);

	set("type","indoors");
	set("objects",([
		__DIR__"obj/case": 1,
		__DIR__"npc/guard" : 1,
	]) );
	set("exits",([
		"west":__DIR__"fyhall",
	]) );
        set("indoors", "chenxiang");
	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
