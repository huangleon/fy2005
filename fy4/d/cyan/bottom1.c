// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�Ųt��̨��");
    set("long", @LONG
��������ת��������ͷ������ֻ������ǧ��ֱû������֮�С�������ǧ
������׹������㾹Ȼ�����ţ��̲�סΪ�Լ��������ң�����Ĵ���������
����һ��СС�ĵ͹ȣ����汳��ɽ�ڣ��������ż��õ����ɣ��е���������
�ǻ�������
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/pine2":1,
	]));
	set("no_fly",1);
	set("item_desc", ([

	"cliff":"��ͷ������ֻ������ǧ��ֱû������֮�С�\n",
	"��":"��ͷ������ֻ������ǧ��ֱû������֮�С�\n",
	"����":"��ͷ������ֻ������ǧ��ֱû������֮�С�\n",

	"ɽ��":"��Ӳ�Ļ�ɫ��ʯ�����ɵ�ɽ�ڡ�\n",

	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",

	]) );
	set("exits",([
  		"east" : __DIR__"bottom2",
	]) );

	set("coor/x",-70);
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


