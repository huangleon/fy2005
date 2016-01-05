#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ���ɺ�ĵ�̺�����ſڱ�ֱ������Զ�����䳤����ֹʮ�ɡ���ͷ������ʮ��
��ʯ�ף���������һ���Ż���ԭ��С��¥������ɽ���������С������ȴ�ǿ��ݲ�
�����ڼ�ƹ�Ի͡�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gate",
  "south" : __DIR__"datang",
]));
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
    set("objects", ([
        __DIR__"npc/g_wushi" : 2,
    ]) );

	setup();
    create_door("north","door", "�ƽ���", "south", DOOR_CLOSED);
}
void init()
{
	object me;
	me = this_player();
	if(interactive(me))
	me->set_temp("intime", time());

}

int valid_leave(object me, string dir)
{
	int in_time;
	
	if (dir == "south")
	{
	in_time = me->query_temp("intime");
	me->set_temp("wait_time", time()-in_time);	
	}
	return ::valid_leave(me, dir);
}
