// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "������");
    set("long", @LONG
������������������ͷ���ֹ�����ʲô�Ϊʲô���������ܶ�����·��
��һ�����ϣ�����룬�㻹����ϸ������ֻ����ï����Ҷ��������֦��������
��Ƭ��񷣬��Χ������ģ�ʲôҲ�����塣
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/shadow":1,
	]));
	set("item_desc", ([


	]) );
	set("exits",([
  		"down" : __DIR__"peak6",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",100);
	setup();
}


void init()
{
	add_action("do_search", ({"search"}));
}

int do_search(string arg)
{
	object me = this_player(),he;
	if (me->is_busy() || me->is_fighting())
	{
		write("��������æ��\n");
		return 1;
	}

	tell_object(me,"������Ҷ֦�����Ĵ�������\n");
	message_vision("һ��ϤϤ������������������֪��$N�ڲ�Ūʲô��\n",me);
	he=present("hidden shadow",this_object());
	if (he || query("get"))
		tell_object(me,"Ȼ����ʲô��û���ҵ���\n");
	else
	{
		set("get",1);
		he = new(__DIR__"obj/jade");
		tell_object(me,"��������һ�鴥�ֱ�����Ӳ�Ķ�����");
		if (he->move(me))
		{
			tell_object(me,"��æ�������\n");
		}
		else
		{
			tell_object(me,"����һ��С�ģ����ʹ������л�����ȥ��\n");
			destruct(he);
		}
	}

	me->perform_busy(4);
	return 1;
}


void reset()
{
	object river,stone,*inv;
	
	::reset();

	if (query("get"))
		set("get",0);

	return;
}
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


