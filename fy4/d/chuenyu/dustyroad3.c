// Room: /d/chuenyu/dustyroad2.c

#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "��ʯС·");
        set("long", @LONG
����һ��ͨ��һ����լ����ʯС·��С�ݾ�����Ķ�������һ�������С��
ƺ����Ķ��ߡ����Ϸ�����һ������·�ڣ����ƺ��������������������Ľ�������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"dustyroad2",
  		"northeast" : __DIR__"home",
  		"north" : __DIR__"smallyard",
	]));

        set("outdoors", "chuenyu");

	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();

}

