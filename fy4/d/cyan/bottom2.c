// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "����ջ��");
    set("long", @LONG
��������㷢���˴�����ֻ��ɽ������ǰһ���žɵ�ջ��������ɽ�ڣ�
ջ����������ã����Ϊ����û�������ݣ�ջ�����̼ܵĶ�ľ���Ѿ���ȱ���룬
�໵̩�룬�д��һЩ��������ɫ����̦���������ɽ����ҡҷ������֨ѽ֨
ѽ�����졣
LONG
NOR
        );
	set("objects", ([


	]));

	set("no_fly",1);
	set("item_desc", ([

	"ľ��":"ջ�����̼ܵĶ�ľ���Ѿ���ȱ���롣\n",
	"��ľ��":"ջ�����̼ܵĶ�ľ���Ѿ���ȱ���롣\n",

	"��̦":"ջ����������̦������С��Ϊ�ϡ�\n",
	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",

	]) );
	set("exits",([
  		"east" : __DIR__"bottom3",
  		"west" : __DIR__"bottom1",
	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (!random(3))
	{
		tell_object(me,HIG"�����һ������ջ���ϴ��˸�������Щˤ�˳�ȥ��\n"NOR);
		me->perform_busy(2);
		return notify_fail(" ");
	}
	else
		tell_object(me,"��һ��һ��ӡ������������ջ��ǰ�У�����\n"NOR);
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


