// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "�t��̨��");
    set("long", @LONG
��һ���䱸ɭ�ϣ������о����������������֮�����������שʯ����
�����£���������������滨��ǹ��������ǽ�������ϣ���ǽ������������
�ڣ�սʱ�ڶ���ϼȿ��Գ���ǯ��������ϼɽ�������ָ�Ӳt��̨�ϵ������
�����Է���֮��Զ�䣬�����ƳǶ�ֱ�������ȵ���ʮ���·����������
LONG
NOR
        );
	set("objects", ([
//	__DIR__"obj/pot":2,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "path6",
	]) );

	set("area","cyan");

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
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


