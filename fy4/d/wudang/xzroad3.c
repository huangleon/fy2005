
inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����ʯ���̳ɵĵ�·����ɨ�ø�Ǭ����������Сͯ�ڽֵ��ϻ���׷����ˣ����
�������Ǻ�ש���ɵķ��ݣ���λ�������е����ڼ���ǰ�������졣
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"xzroad2",
		"south" : __DIR__"road1",
        "southeast" : __DIR__"xzroad4",
        "southwest" : __DIR__"xzroad5",
		"west" : __DIR__"xzhouse2",
		"east" : __DIR__"xzstore2",
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
