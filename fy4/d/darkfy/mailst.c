
inherit ROOM;

void create()
{
	set("short", "����վ");
	set("long", @LONG
���ѷ����ķ�����վ����ש���߶��ٸ����ֲ�ɣ�ĸо���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"wcloud2",
	]));
//	set("objects", ([
//		__DIR__"npc/officer": 1
//	]) );

	set("coor/x",-20);
	set("coor/y",10);
        set("coor/z",-300);
	setup();
}

