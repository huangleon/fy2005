// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "����´");
    set("long", @LONG
����´ɽ�ƴ��䣬��ʯ��ɣ��ͱ���ͻ���뼹����������ǧ�𣬶���һ��
���ڣ�紵��֮�£����˵����ľ���ǰ����С���α�����Ⱥɽ����Ϊ����´
���֡��������¡�������ʫ�ƣ����ƴ��Ͳ࣬��ĺ��ͻ����Ÿ���Զ�䣬�ν�
���߳塣
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westdown" : __DIR__"path5",
  		"northup" : __DIR__"peak2",
	]) );

	set("outdoors", "cyan");

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",70);
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


