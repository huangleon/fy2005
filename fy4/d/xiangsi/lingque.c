// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����̶");
        set("long", @LONG
���ɫ�ı������������̶�ߵĲ�ľ���÷���ï�ܡ�һ���ı̵�̶ˮ��
��һö�峺���������ɫˮ������Ƕ��������εĲ�ľ���С�Զɽ�ϴ�������
ϸ���������һ�ж���ô��г��������һƬ��ɫ��������
LONG
        );
	set("objects", ([
		__DIR__"npc/jiang" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"shuangtian",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",-10);
	setup();
}



int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"shuangtian");
	if (!exitroom)
		exitroom = load_object(__DIR__"shuangtian");
	if (userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"�G��͵���˼�Ů����ϴ����ʲô����\n"NOR);
	}
}
