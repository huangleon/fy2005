
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ʮ�ָ�����²�����أ�������������ʯ���̳ɵģ�����ȥ�������죬
û����ʮ�߾���Щ���ɫ�Ĺ��Σ������ǵƻ𣬶�����ʯͷ�﷢����ӫ�⡣�����
ǰ����һ˿�����ս�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"hole4",
  		"south" : __DIR__"hole",
	]));
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
