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
	__DIR__"obj/grass":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "peak7",
  		"eastdown" : "pathb",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",60);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();



	river = present("Ұ��", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 && !random(2))
	{
		stone = new(__DIR__"obj/brokenflute");
		if(stone)
			stone->move(river);
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


