// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "������");
    set("long", @LONG
�����ȵ���������ӫӫ��ʯ����һ������Ϫ��������������С����Ϫˮ��
������������������м�����ণ���Ҳ���һ�����顣�������Ѿ�����������
������һЩǰ����ˮ��С����һ���Ҳ��������������ԲԲ�Ĵ��۾�����ش�
�����㡣
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/cat":1,
	__DIR__"npc/turtle":1,
		__DIR__"obj/river" : 1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path8",
  		"southup" : "peak11",
  		"northup" : "peak10",
  		"eastdown" : "patha",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("Ϫˮ", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/stone");
		if(stone)
			stone->move(river);
	}
	return;
}



int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir != "southup")
		if (REWARD_D->riddle_check(me,"���Ļ���") == 1) 
			return notify_fail("������ȥ��ʦ���ɡ�\n");

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


