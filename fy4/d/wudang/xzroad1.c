
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
		"north" : __DIR__"xiaozhen",
		"south" : __DIR__"xzroad2",
		"east" : __DIR__"xzdong",
        	"west" : __DIR__"xinghuacun",
	]));
	set("outdoors", "wudang");
	set("objects", ([ 
		__DIR__"npc/dog": 1,
		__DIR__"npc/xiaotong": 2 
	]) );
	set("coor/x",0);
	set("coor/y",90);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);

}
