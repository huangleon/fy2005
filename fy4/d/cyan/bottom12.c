// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	// ����ʿ�������ý��������ô󽫾�

	set("short", MAG"����"NOR);
    set("long", @LONG
�ӷ��ŵ�ս���ߵ����Ѫ��ζ��ʱ������࣬������Ũ�������֮��
ȴ��Ȼ������������ݲ�����һƬ���ߵ����ؼ䣬͸���������︯��ܻ���
��Ϣ����������ս���ϵ�Թ������������ǻ��Ų�����ȥ�������ߵ�����
���������һ���������İ�����
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/ghost1":1,
	__DIR__"npc/ghost2":1,
	__DIR__"npc/ghost3":1,
	__DIR__"npc/ghost4":1,

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
  		"north" : __DIR__"bottom11",
  		"west" : __DIR__"deadforest2",
  		"east" : __DIR__"bottom13",
	]) );

	set("coor/x",-20);
	set("coor/y",20);
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


