// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
string look_stone();

void create()
{
	set("short", "��ɣ��ľ��������");
    set("long", @LONG
���СС������������ֻ�������ﾹȻ������һ��СС�ķ��䣬�����а�
����̳̳�޹ޣ��������¡�������Ѳ��һ�η��䣬�ż����з�СС��ľ������
���䣬�и�СС���������ڴ��ϡ�
LONG
NOR
        );
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/woodwaiter":1,
	]));
	set("no_fly",1);
	set("item_desc", ([
		"СС��ľ��":	"СС����˯��СС�Ĵ���\n",
		"ľ��":			"СС����˯��СС�Ĵ���\n",	
		"��":			"СС����˯��СС�Ĵ���\n",	
	]) );
	set("exits",([
  		"out" : __DIR__"bottom7",
	]) );

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-200);
	setup();
    create_door("out","door","СС����","enter",DOOR_CLOSED);
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


