// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", HIR"�޻�֮��"NOR);
    set("long", @LONG
һ�����������ͻȻ������߷���������һ�ֽ������ĺ��������䣬
�����ô���������֮�䡣Ũ���д�����һ�����������ܵļ�Х������ͷ����
�����Ԥ�У�ֻ��������ǰȥ���ͻ��߽�������������˼�����磬������
�ѻ�ͷ��
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",

	]) );
	set("exits",([
  		"north" : __DIR__"bottom5",
  		"east" : __DIR__"bottom10",
  		"west" : __DIR__"bottom3",
	]) );

	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir == "west")
		return notify_fail("����������������ǿ���ޱȣ���پ��ٲ�Ψ�衣\n");

	tell_object(me,CYN"�����䱸��С�����������������ȥ������\n"NOR);
	me->perform_busy(1);
	return ::valid_leave(who,dir);
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


