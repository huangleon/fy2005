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
		"east":__DIR__"milin3",
		"south":__DIR__"milin1",
		"west":__DIR__"milin7",
		"north":__DIR__"milin20",
	]) );
	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
