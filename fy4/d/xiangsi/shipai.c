// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ʯ�Ʒ�");
        set("long", @LONG
����ɽ������ǰȴ������һ�����¡������������ֱ���һ����������ټ
��ɽ�ң����汻�˴�ĥ���羵���⻬�����������������֡�����һ������
���ֵĲݾ���ɽ����ȥ��������Ư���ŵ�����ľҶ���㣬��������΢������ҡ
�Σ���ʱ���ù�������ӡ�
LONG
        );
	set("objects", ([
		__DIR__"obj/rock4" : 1,
	]));
	set("exits",([
  		"northdown" : __DIR__"xiangsi",
  		"southup" : __DIR__"haoyue",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
    replace_program(ROOM);
}
