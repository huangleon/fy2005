
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�䵱��");
	set("long", @LONG
��ɫ��Χǽ����ɫ�Ĵ��š����Ϲ���һ����ң����顰�䵱�ۡ��������ɷ���
�Ĵ��֡��������Ҹ�����һֻ��ΰ��ʯʨ��һ��ͷ����ɫ���ڣ�����ɫ���۵�֪
�͵��ˣ����Ŷ�����
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"road3",
		"enter" : __DIR__"wudang1",
	]));
	set("objects", ([ 
		__DIR__"npc/wtaoist" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object *enemy, ob;
        int i;

        if( userp(me) && (ob=present("waiter taoist", this_object()))) {
		enemy = ob->query_enemy();
		i = sizeof(enemy);
		while(i--) {
                	if( enemy[i] == me )
                                return notify_fail(HIY + ob->name()+"��" + me->name() 
				+ "�ȵ������ܣ�û��ô���ף�\n" + HIR + ob->name() + 
				"��" + me->name() + "���˻�����\n" +NOR);
                }
        }
        return 1;
}

