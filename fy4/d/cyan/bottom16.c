// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "����ž�");
    set("long", @LONG
�뿪Ѫ����ϢŨ��Ĺȵأ����������Դ�Ϣ����ǰ��һ��ҡҡ�λε�����
����ֱ���������ģ������¶��濴ȥ��ֻ��һ����ľ�ĸ������������֮�У�
��������ע�⡣ֻ���������ʧ�ޣ���������������ȣ�������ȥ�ض���ʬ��
�޴棬�����Ჽǰ����Ҫ������ԥ��
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);
	set("item_desc", ([

	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",

	]) );
	set("exits",([
  		"north" : __DIR__"bottom17",
  		"west" : __DIR__"bottom11",
	]) );

	set("coor/x",-10);
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
		tell_object(me,HIG"�����һ�����������ϴ��˸�������Щˤ�˳�ȥ��\n"NOR);
		me->perform_busy(2);
		return notify_fail(" ");
	}
	else
		tell_object(me,"��һ��һ��ӡ����������������ǰ�У�����\n"NOR);
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


