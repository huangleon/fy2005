#include <ansi.h>
inherit ROOM;
#include "milin.h"
void create()
{
	set("short", HIY"����"NOR);

	set("long", @LONG
����һƬ���֣���Χ��ľ������������Ʊ��գ����ܻ�谵����������һЩ˵
�������ֵİ�ɫҰ����������Ҷ�̵أ�����ȥɳɳ���죬���һ�ŵ�һ�ŵ���ǰ��
����������Щ���ģ��������·�˰ɡ�
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("attribute","jin");
	set("exits",([
		"east":__DIR__"milin12",
		"south":__DIR__"milin16",
		"west":__DIR__"milin18",
		"north":__DIR__"milin22",
	]) );

	set("coor/x",-10);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

