// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();
string look_stone2();
string look_stone3();

void create()
{
	set("short", "�ľ����");
        set("long", @LONG
���ȷɼ���ɽ��֮�䣬��ԭ��������ʮ�ɵļ���ɽͷ����һ�����ٰ�
�ɽ��ȣ��·����ն����������������ϣ���������ľ��������ů��չü����
֮�⣬ֻ�����ҿտգ��ƺ���ӿ���ڡ��������ϸ����������΢����ɽ��
���ȶ�����ֻ�����ĳ����������ɰ
LONG
        );
	set("objects", ([
//		__DIR__"obj/desk2" : 1,
	]));
	set("exits",([
  		"east" : __DIR__"hanquan",
  		"west" : __DIR__"houmen",
  		"south" : __DIR__"wangji",
	]) );

	set("item_desc", ([
		"����": (: look_stone :),
		"צӡ": (: look_stone2 :),
		"�ۼ�": (: look_stone3 :),
	]) );
	set("indoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}


string look_stone()
{
	object me = this_player();
	if (REWARD_D->riddle_check(me,"������Թ") != 1 
		&& REWARD_D->riddle_check(me,"������Թ") != 2	// if the bag is lost before the ����
		&& REWARD_D->riddle_check(me,"������Թ") != 9	// if the bag is lost before the �
		)
		return "�ľ�̼ܵ����ȣ�����ȥ������ů��\n";
	tell_object(me,"���ȵĽ���������һ��СС��צӡ������ʲô�������϶����ĺۼ���\n");
	me->set_temp("annie/xiangsi_master",2);
	return " ";
}

string look_stone2()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 2)
		return "��Ҫ��ʲ�᣿\n";
	tell_object(me,"צӡɢ������÷�������ӣ�����������Сè���µġ�\n");
	return " ";
}

string look_stone3()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 2)
		return "��Ҫ��ʲ�᣿\n";
	tell_object(me,"���ϵĺۼ�һֱ������ȥ�ˣ���ʧ�ڲ�Զ����\n");
	return " ";
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


