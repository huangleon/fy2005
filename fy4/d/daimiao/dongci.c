#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","���μ�");
  set("long",@LONG
���ܵ����ڣ����������������ǽ���ϣ��ʻ��С�̩ɽ�����ϻ���ͼ����ͼ
�Ժ���Ϊ�磬��Ϊ�����ϡ�����Ϊ�����ǡ������μ�������ͭ��������������һ�ܣ�
ֱ�������ߣ�ԭ��ң��ͤ�б�ϼԪ�������Ĺ��
LONG
  );
  	set("exits",([
        	 "west":__DIR__"tiankuang",
        ]));
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	object ob;
	add_action("do_say","say");
}

int do_say(string arg)
{
	object me = this_player(),room;
	if (arg != "����������ò�࣬��ˮ�����Ѷ���")
		return 0;
	if (REWARD_D->riddle_check(me,"̽��׷Դ") < 8 && !REWARD_D->check_m_success(me,"̽��׷Դ"))
		return 0;
	message_vision(CYN"��������ͻ����⣬һƬ��âת�ۼ佫���μ����֡�\n"NOR,me);
	me->add_temp("block_msg/all",1);
	if (!room = find_object(__DIR__"maze_enter"))
		room = load_object(__DIR__"maze_enter");
	me->move(room);
	me->add_temp("block_msg/all",-1);
	tell_room(this_object(),CYN"�����⻪������ȥ�����Ȼ�����������һ�ˡ�\n"NOR);
	tell_object(me,CYN"��ǰ��ɫ�Ĺ�â������ȥ���㷢���Լ��Ѳ��ڶ��μ��С�\n"NOR);
	return 1;
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

