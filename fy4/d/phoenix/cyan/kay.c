// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "߱��̨");
    set("long", @LONG
�ߵ����һƬ���ޱ��ڵ��ҵ�ͻأ���Ի����������֡��ҵؾ�����һ��
�����������ɫʯ�ۣ������½���������ɣ�ʯ�۱�Ե��һ���羵��⻬�ı�
״��ʯ��ʯͷ����δ�����κ����֡�
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock3":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"west" : "forest1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",20);
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


