
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�Ͱ�ʯ��");
        set("long", @LONG
����һ��Ͱ������ӣ��ıڶ��Ǻ�ʵ�ĺ�ʯ�����д���Щ����΢�ĳ�����ʯ��
��������ĵط�����һ�㱡������̦��ʯ�ݵ����������һ��ʯ�ţ��򿪻�ա���
·Ҳ�����ʯ��֮�󣬿��Ǿ�����һ���Ų���������
LONG
        );
	set("room_num",3);
	set("exits",([
//  		"west" : __DIR__"couplemaze_"+(query("room_num")-1),
//  		"east" : __DIR__"couplemaze_"+(query("room_num")+1),
//  		"north" : __DIR__"couplemaze_"+(query("room_num")-6),
//  		"south" : __DIR__"couplemaze_"+(query("room_num")+6),
	]) );
	set("exist_exits",query("exits"));
	// nothing
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
	object center;
	center = find_object(__DIR__"couplemaze_center");
	if (!center)
		center = load_object(__DIR__"couplemaze_center");
/*
   	if( dir == "west")
	{
		center->close_all_path();
		center->open_path(6);
		message_vision(CYN"һ����Ƶĺ�����ңң����������\n"NOR,me);
	}

   	if( dir == "north")
	{
		center->close_all_path();
		center->open_path(9);
		message_vision(CYN"һ����Ƶĺ�����ңң����������\n"NOR,me);
	}
*/
	return 1;
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

