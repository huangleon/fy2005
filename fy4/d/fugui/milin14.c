#include <ansi.h>
inherit ROOM;
#include "milin.h"

void create()
{
	set("short", HIR"����"NOR);

	set("long", @LONG
����һƬ���֣���Χ��ľ������������Ʊ��գ����ܻ�谵����������һЩ˵
�������ֵĺ�ɫҰ����������Ҷ�̵أ�����ȥɳɳ���죬���һ�ŵ�һ�ŵ���ǰ��
����������Щ���ģ��������·�˰ɡ�
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","huo");
	set("exits",([
		"east":__DIR__"milin15",
		"south":__DIR__"milin19",
		"west":__DIR__"milin13",
		"north":__DIR__"milin9",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
