// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "����");
    set("long", @LONG
��ӳ�����������µ�ˮ����͸�������ȵĶѶѰ�ʯ�������������������
�£�ϸխˮ�������ߣ���̵�Ұ�ݳ��÷���ï�ܣ�Ҳ�˵ÿ���������Ƣ������
����С����ӯ�ɣ�����������Ҳ�����������ġ�
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/fox":1,
	__DIR__"npc/dwg":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "patha",
  		"eastdown" : "peak12",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",50);
	setup();
}



void reset()
{
	object river,stone,*inv;
	
	::reset();

	if (!query("grass"))
	{
		set("grass",1);
		river= new(__DIR__"obj/grass2");
		river->move(this_object());
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


