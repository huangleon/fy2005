// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", YEL"������"NOR);
    set("long", @LONG
������խ��ɽ�죬ӭ�������һƬ���ص����֡���δ�����ĸ��ֲ����ľ
��������ں�����������Ų��þ�Ȼ����ԶԶ��ȥ������ī���ϻ�δ������
ľ�塣��ͷ������������������ľҶ����һƬ�Ա̣���������ǳǳ�Ķ�ƣ�
֦����ƽ�ߣ�����Ϊһ��������ܵ�������
    ��֪���ļ��ڣ�΢�硣
    ��ɫ�Ĺ��ߴ�������ǳǳ��͸��������
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"northdown" : "peak5",
  		"southdown" : "forest4",
	]) );
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	// 3 ways to pass: 
	// kill 2 keepers (set mark to 5);
	// get invition (set mark to 6);
	// or rob the ��� (set mark to 7)
	if (present("shaolin monk") && dir == "southdown")
		if (!REWARD_D->check_m_success(me,"ɱ����") && !REWARD_D->check_m_success(me,"���ȥ") && !REWARD_D->check_m_success(me,"���") )
			return notify_fail("�����ɺ��е��������ӷ���λʩ������������\n");

	if (!random(7))
		tell_object(me,YEL"�������ŵ���һ�ֵ����Ľ�ɫ��������\n"NOR);

	if (dir == "southdown")
		if (REWARD_D->riddle_check(me,"���Ļ���") >= 4) 
			if (REWARD_D->riddle_check(me,"���Ļ���") <= 6) 
				REWARD_D->riddle_set(me,"���Ļ���",7);
					


	return ::valid_leave(who,dir);
}


void reset()
{
        object *inv, ob;
        int i;
        ::reset();
        ob=present("shaolin monk", this_object());
        inv = all_inventory();
        if(ob)
		{
			ob->dismiss_team();
			for(i=0;i<sizeof(inv);i++)
				if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
					ob->add_team_member(inv[i]);
        }
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


