// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�ڰ�֮��");
    set("long", @LONG
һƬ����ֹ������ڣ���������������������������������������������
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-400);
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


