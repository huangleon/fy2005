// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "����̨");
    set("long", "

�������⡡�����û�����С���ʲ����ô�����ء����𡡡���

"
NOR
        );
	set("objects", ([

	__DIR__"npc/ho":1,

	]));
	set("item_desc", ([
	]) );
	set("exits",([
  		"southdown" : "peak7",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",80);
	setup();
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


