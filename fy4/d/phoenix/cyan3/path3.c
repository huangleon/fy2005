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
	__DIR__"obj/cliff":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "forest2",
  		"eastdown" : "path2",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",30);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (!random(3))
	{
		tell_object(me,CYN"������խ��ɽ���м���ǰ�С�\n"NOR);
		me->perform_busy(1);
	}
	else if (!random(3))
	{
		tell_object(me,CYN"��Ŭ������һ����խ��ɽ·����С�Ĳȵ���������ʯ��ʹ�����顣\n"NOR);
		me->receive_wound("kee",20);
		me->set_temp("last_damage_from","��ɽ��������ͷ��Ѫ�������߶�����");
	}
	return ::valid_leave(who,dir);
}


void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("ɽ��", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 && !query("get"))
	{
		set("get",1);
//		stone = new(__DIR__"obj/sachet");
//		if(stone)
//			stone->move(river);
	}
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


