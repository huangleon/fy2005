
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���Ӳ��󣬵����õú����¡����濿ǽ����һ�Ŵ󴲣�����ѩ�ף�����ո�¡�
���洲ͷ��һ����ױ̨��̨�Ϸ���һ��ͭ����������֬��
LONG
	);
	set("exits", ([
                "north" : __DIR__"groad5",
	]));
	set("objects", ([
                __DIR__"npc/hua" : 1,
	]));
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
