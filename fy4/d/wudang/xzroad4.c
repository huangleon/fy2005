
inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����ʯ���̳ɵĵ�·����ɨ�ø�Ǭ����������Сͯ�ڽֵ��ϻ���׷����ˣ����
�������Ǻ�ש���ɵķ��ݣ���Զ������ңң����һ������ܸߵ���ɫɽ�ԡ�
LONG
	);
	set("exits", ([ 
        "northwest" : __DIR__"xzroad3",
        "southeast" : "/d/bawang/shanlu",
        "east" : "/d/bawang/mantoudian",
	]));
	set("outdoors", "wudang");
	set("coor/x",60);
	set("coor/y",30);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
