inherit ROOM;

void create()
{
	set("short", "����լ");

	set("long", @LONG
���Ǽ�𸮵��᷿���Ŵ�������ţ����ߺܻ谵������������ֻ���м��
��һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG);
	set("type","indoors");
	set("exits",([
		"northeast":__DIR__"jinlin",
		"northwest":__DIR__"jinyuan",
	]) );
	set("coor/x",60);
	set("coor/y",40);
	set("coor/z",0);
	set("objects" , ([
		__DIR__"npc/guard2":1,
		__DIR__"npc/guard2a":1,
	    __DIR__"obj/bed" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
