// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "������"NOR);
    set("long", @LONG
����Ŀ������͸��ŨŨ���ȳ�֮�����������ľ��֪�ι��Ѿ����øɾ�����
����Ȼͦ��������֮�ϣ���δ�ɿݣ�ȴ��һ��һ��ĸ��ã���һ��Ũ��ɫ��֭Һ��
�����������������������Ĳ�����Ǭ���֦Ҷ�������Ժ��İܻ������ࡣ
LONG
        );
	set("objects", ([
		__DIR__"obj/swamp":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northup" : "forest2",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",30);
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


