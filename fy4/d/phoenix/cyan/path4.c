// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "ɽ��");
    set("long", @LONG
�����ɽ�������ɽ�������������ɽ϶��ǡ��Щ����·���м������
���Ǽ�Ӳ�Ļ��ң�Ω��һ˿΢���Ĺ�â��ͷ����ʯ����©�¡�����΢�⣬����
�ɿ���խ�������������Ҷ��ҷ�������ʯ���ڽ����ߣ���֪ͨ��η���
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/container":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "forest3",
  		"westup" : "forest4",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;
		if (REWARD_D->riddle_check(me,"�ع�����") == 99) 
		{
			return notify_fail("���ȥ·�����ﵲס�ˣ�\n");
		}

			REWARD_D->riddle_set(me,"�ع�����",99);
			who=new(__DIR__"npc/j2");
			who->move(this_object());
			message_vision(HIR BLK"�Һ�ɫ��������Ȼ������ǰ����������ɢȥ����ƾ���ֳ�һ����Ӱ��\n"NOR,me);
			message_vision(HIR"$N�Ա�����ߵ�����ԭ�ˣ���������Ϊֹ�ˡ�\n\n"NOR,who);	// not typo.
			who->kill_ob(me);
			me->kill_ob(who);
			return notify_fail("\n");

	return ::valid_leave(who,dir);
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


