#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɳѨ����");
	set("long", @LONG
������һ�������ܶ������ܺںڵģ���Լ���Կ�����Χ��ʯ�ܲ���������һ��
��������һ�����Ӵ�����������Լ��������ˮ����
LONG
	);
	set("exits", ([ 
  		"west" : __DIR__"shaxue",
		"eastup" : __DIR__"dongd2",
	]));

	set("indoors", "quicksand");

	set("coor/x",-1040);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}
