// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����ˮ�");
        set("long", @LONG
����С��¥�����Ϫ���ϣ�ȫȻ�������������Ⱦһ���������߽�ͤ��
������ˮ����������������ϰϰ����������������˶��������к쳾������
�Ĳ������񣬱���Ҫ�˷��ȥ������ȫ����������Ȼ��
LONG
        );
	set("objects", ([
		__DIR__"obj/desk" : 1,
		__DIR__"npc/gits" : 1,
	]));
	set("exits",([
  		"west" : __DIR__"qingxi",
	]) );

	set("indoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	me->delete_temp("annie/gits");
	return ::valid_leave(who,dir);
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("bamboo desk", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/yawnbook");
		if(stone)
			stone->move(river);
	}
	return;
}

/*
���ݺ�ﻨ
�׻�,����Ȫ��ˮ��̲��ˮȪ��ɬ������,������ͨ����Ъ��
*/