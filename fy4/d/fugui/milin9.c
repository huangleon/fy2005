#include <ansi.h>
inherit ROOM;
#include "milin.h"
void create()
{
	set("short", HIG"����"NOR);

	set("long", @LONG
����һƬ���֣���Χ��ľ������������Ʊ��գ����ܻ�谵����������һЩ˵
�������ֵ���ɫҰ����������Ҷ�̵أ�����ȥɳɳ���죬���һ�ŵ�һ�ŵ���ǰ��
����������Щ���ģ��������·�˰ɡ�
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","mu");
	set("exits",([
		"east":__DIR__"milin10",
		"south":__DIR__"milin8",
		"north":__DIR__"milin14",
		"west":__DIR__"milin4",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
