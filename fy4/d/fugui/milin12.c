#include <ansi.h>
inherit ROOM;
#include "milin.h"

void create()
{
	set("short", YEL"����"NOR);

	set("long", @LONG
����һƬ���֣���Χ��ľ������������Ʊ��գ����ܻ�谵����������һЩ˵
�������ֵĻ�ɫҰ����������Ҷ�̵أ�����ȥɳɳ���죬���һ�ŵ�һ�ŵ���ǰ��
����������Щ���ģ��������·�˰ɡ�
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","tu");
	set("exits",([
		"east":__DIR__"milin13",
		"south":__DIR__"milin11",
		"west":__DIR__"milin17",
		"north":__DIR__"milin7",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
