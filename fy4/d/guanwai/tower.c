#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���п�Լʮ�ɸߵļ����������ڲ����ղ������⣬�������ֻ��������
̦������Ȼ�ƾɣ�ȴ�кܶ��ϵ���ͽ������Ĥ�ݡ�
LONG
	);
	
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"templeyard2",
		"east" : __DIR__"templeyard",
		"west" : __DIR__"chanhouse",
		"north" : __DIR__"templeyard3",
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("NONPC",1);
	set("objects", ([
		__DIR__"npc/keeper" : 1,
	]));

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
