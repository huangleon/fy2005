
#include <ansi.h>
inherit ROOM;

void create()
{
	object box;
	set("short", "�Ͱ�ʯ��");
        set("long", @LONG
����һ��Ͱ������ӣ��ıڶ��Ǻ�ʵ�ĺ�ʯ�����д���Щ����΢�ĳ�����ʯ��
��������ĵط�����һ�㱡������̦��ʯ�ݵ����������һ��ʯ�ţ��򿪻�ա���
·Ҳ�����ʯ��֮�󣬿��Ǿ�����һ���Ų���������
LONG
        );
	set("room_num",24);
	set("exits",([
  		"west" : __DIR__"couplemaze_"+(query("room_num")-1),
	]) );
	set("objects", ([
		__DIR__"obj/box" :1,
	]) );
	set("exist_exits",query("exits"));
	// nothing
	set("no_fly",1);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	box = present("woodcase",this_object());
	if (box)
		new(__DIR__"obj/map")->move(box);
	if (box)
		new(__DIR__"obj/map")->move(box);
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

