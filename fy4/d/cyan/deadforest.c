// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "������"NOR);
    set("long", @LONG
����Ŀ������͸��ŨŨ���ȳ�֮�����������ľ��֪�ι��Ѿ����øɾ�����
����Ȼͦ��������֮�ϣ���δ�ɿݣ�ȴ��һ��һ��ĸ��ã���һ��Ũ��ɫ��֭Һ��
�����������������������Ĳ�����Ǭ���֦Ҷ�������Ժ��İܻ������ࡣ
LONG
        );
	set("objects", ([
		__DIR__"obj/swamp":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northup" : __DIR__"forest2",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",30);
	setup();
}


void init()
{
	add_action("do_west","go");
}


int do_west(string arg)
{
	object me = this_player();
		object room;

	int i;
	if (arg != "east")
		return 0;
	if (!REWARD_D->check_m_success(me,"��ϼ֮��"))
		return 0;

	room=find_object(__DIR__"deadforest2");
	if(!objectp(room)) 
        room = load_object(__DIR__"deadforest2"); 
	me->move(room);
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


