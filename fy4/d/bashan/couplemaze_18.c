
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
	set("room_num",18);
	set("exits",([
//  		"west" : __DIR__"couplemaze_"+(query("room_num")-1),
//  		"east" : __DIR__"couplemaze_"+(query("room_num")+1),
//  		"north" : __DIR__"couplemaze_"+(query("room_num")-6),
//  		"south" : __DIR__"couplemaze_"+(query("room_num")+6),
	]) );
	set("exist_exits",query("exits"));
	// nothing
	set("no_fly",1);
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
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

