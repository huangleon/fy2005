// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	// �������䣬����ʿ�������ý��������ô󽫾�

	set("short", HIR"Ѫսɱ��"NOR);
    set("long", @LONG
�ߵ�ɽ������һ�����أ��㵹����һ��������ֻ���ȵ���ʬ���Ұ����
�����ǲл��ĵ�ǹ��ꪣ�����������յĽ����ɵ��ڵأ����۵İ׹������
�ƺ���ȻδϨ��������Ʈ���ŵ�����Ѫ����ζ��������������ʿ������ǰ��
�������·�ս��ֻ�Ǹոս�����
LONG
NOR
        );
	set("objects", ([

	__DIR__"npc/skeleton1":2,
	__DIR__"npc/skeleton2":2,
	__DIR__"npc/skeleton3":1,
	__DIR__"npc/skeleton4":1,

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
  		"south" : __DIR__"bottom12",
  		"east" : __DIR__"bottom16",
  		"west" : __DIR__"bottom10",
	]) );

	set("coor/x",-20);
	set("coor/y",30);
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


