// ; annie 07.2003
// dancing_faery@hotmail.com
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ʯ��");
        set("long", @LONG
�����Ǻ�̶�����һ��ټ���ʯ����Ѿ���������������ȴ�������Ѿ�������
�����������ȥ��ֻ������һ��������£�����ƮƮ�����ճյĴ���Ҷ�ѣ�����
����˼���������裬�·����ô�ڴ鴽�崵�İ�������У������˹�����������
������ͷ������
LONG
        );
		set("objects", ([
		__DIR__"npc/du2" : 1,
	]));   
    set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",50);
	set("coor/z",20);
	setup();
}

void init()
{
    	add_action("do_swim", "swim");
}

int do_swim()
{
	object me, obj;

	me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	message_vision("$Nһ������������ˮ�С�\n", me);
	tell_object(me,"����һ������ӿ���������ƹ�̶��һƬï��ˮ�ݡ�\n");
	obj = load_object(__DIR__"pond");
	me->move(obj);
	tell_object(me,"��æ�����Ĵ�ˮ������̶�ߡ�\n");
	message("vision", me->name() + "ʪ�����Ĵ�ˮ������������\n", environment(me), me);
	return 1;
}
