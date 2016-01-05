// Room: /d/pk/entry.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���˳����");
	set("long", @LONG
������һ�䲻����С�ݣ����а���һ�����ӣ���������һ���ˣ�
��Ц�����Ŀ����㡣�������һ���ţ������ţ�����ں����ģ�Ҳ��֪
��ͨ�������������ȥ�ǿ��������Ĵ�֣���������������
LONG
	);
	set("exits", ([
		"north" : __DIR__"ready",
                "down"  : "/d/fy/fysquare",
	]));

        set("objects", ([
                __DIR__"npc/wu" : 1,
        ]));

        set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north")
                return notify_fail("���ϴ�ȵ�������վס���Ƕ�����������롣\n");

        return ::valid_leave(me, dir);
}
