// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit __DIR__"ann_room.c";

void create()
{
	object river,stone;
	set("short", "�������");
        set("long", @LONG
�ߵ����ֱ�Ե��һ�����ѵ�СϪ��б���������ǰ��Ϫˮ�����������
һ���Բ�ɰ�����ʯ�����������������ˮ���˴���Ϫ�ߵ�ʯ���ϣ��Ƽ�����
������ȥ���������齦�飬�ö���������Ŀ��ɽ����Լ�ɼ�һ�Ǻ��ܷɹ�����
�����У����ߴ�����ױ��ѩ�����ⶫ��֮�����Ǻ�����
LONG
        );
	set("objects", ([
		__DIR__"npc/mengye" : 1,
	]));
	set("exits",([
  		"up" : "/d/fy/fysquare",
  		"down" : "testroom",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
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
