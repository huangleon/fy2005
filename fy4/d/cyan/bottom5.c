// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", CYN"�Ļù�"NOR);
    set("long", @LONG
�˴�������У������ѱ棬�����Կգ�ǰ���ĵ�·������һ���Ӵ���ƥ
����ʯ����ʯ�����ų������֣�����ľ�ɫ���㿵��������������֣���
��ķ��ӹ�������������ʱ���ַ�����ĵ�����ɫ��ֱҪ�����Լ���Ȼ����
�˼䡣
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/rock4.c":1,

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
  		"south" : __DIR__"bottom4",
  		"east" : __DIR__"bottom6",
  		"west" : __DIR__"bottom8",
	]) );

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

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


