#include <ansi.h>
inherit ROOM;
#include "milin.h"

void create()
{
	set("short", HIC"����"NOR);

	set("long", @LONG
����һƬ���֣���Χ��ľ������������Ʊ��գ����ܻ�谵����������һЩ˵
�������ֵ���ɫҰ����������Ҷ�̵أ�����ȥɳɳ���죬���һ�ŵ�һ�ŵ���ǰ��
����������Щ���ģ��������·�˰ɡ�
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","shui");
	set("exits",([
		"east":__DIR__"milin5",
		"south":__DIR__"milin25",
		"west":__DIR__"milin19",
		"north":__DIR__"milin15",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
