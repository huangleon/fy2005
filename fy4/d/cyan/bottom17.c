// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", HIB"��������"NOR);
    set("long", @LONG
ɽ�����һ��ͨ������ľ�����ĸ�����������ɽ�����֮�У������紵
����ȴ��Ȼ������˿������������ʴ�̵ĺۼ��������������������һ���ʯ
ʨ�ӣ�����������ص����㣻̧ͷ������ֻ���Ҷ������ɷ�������ĸ���ɫ��
�̴��֣�
��������������������[45m[1;33m�X�������������������������[[2;37;0m
��������������������[45m[1;33m�O���������ԡ����졡���ԡ��O[2;37;0m
��������������������[45m[1;33m�^�������������������������a[2;37;0m����������������

LONG
NOR
        );
	set("objects", ([

	__DIR__"npc/lion":2,
	__DIR__"npc/ye":1,

	]));
	set("no_fly",1);
	set("item_desc", ([

	"west":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"east":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"north":"ɽ���д���������ʲôҲ�ֱ治�����\n",
	"south":"ɽ���д���������ʲôҲ�ֱ治�����\n",

	]) );
	set("exits",([
  		"south" : __DIR__"bottom16",
		"enter" : __DIR__"maze/entry",
	]) );

	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",-100);
	setup();
}

/*
int	valid_leave(object who, string dir)
{
	if (dir != "enter")
		return ::valid_leave(who,dir);

	if (!present("ʯʨ��",this_object()))
		return ::valid_leave(who,dir);
	write("����������ʯʨһ˫Բ���������㣬�����ȵ���ͣס�Ų���\n");
	return notify_fail("");
}*/

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


