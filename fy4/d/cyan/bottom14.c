// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", BLU"ب�Ż��"NOR);
    set("long", @LONG
һɲ�Ǽ䣬������������ش��ڵ�ԭ���и�����ɫ�ľ޴���ᦲ�����
���һ����̳���룬������ù�׭�����[45m[1;37m���߲�Ϣ[2;37;0m�ĸ����֣���Χ��������
������������޵Ļ��飬����������ˮ�����������������ɢ��һ���ؿ�
ή�������Ϣ��
LONG
NOR
        );
	set("objects", ([
		__DIR__"npc/flag":1,
		__DIR__"obj/altar":1,
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
  		"west" : __DIR__"bottom13",
	]) );

	set("coor/x",-10);
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


