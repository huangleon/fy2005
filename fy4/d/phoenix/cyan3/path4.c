// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "ɽ��");
    set("long", @LONG
�����ɽ�������ɽ�������������ɽ϶��ǡ��Щ����·���м������
���Ǽ�Ӳ�Ļ��ң�Ω��һ˿΢���Ĺ�â��ͷ����ʯ����©�¡�����΢�⣬����
�ɿ���խ�������������Ҷ��ҷ�������ʯ���ڽ����ߣ���֪ͨ��η���
LONG
NOR
        );
	set("objects", ([

	__DIR__"obj/container":1,
	__DIR__"npc/guard1":2,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "forest3",
  		"westup" : "forest4",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}



int	valid_leave(object who, string dir)
{
	object me;
	string msg;
	me = who;

	if (present("shaolin monk") && dir == "eastdown" && userp(who))
		if (!REWARD_D->check_m_success(me,"��ɱ����") && !REWARD_D->check_m_success(me,"��������ɽׯ") && !REWARD_D->check_m_success(me,"������ƽ") )
		{
				me->set_temp("aaa",1);
				return notify_fail("�����ɺ��е��������ӷ�������λʩ���Ǻ���"CYN"����"NOR"��("HIW"answer"NOR")\n");
		}

	if (dir=="eastdown" && userp(who))
		me->perform_busy(3);

	if (!random(7))
		tell_object(me,YEL"�������ŵ���һ�ֵ����Ľ�ɫ��������\n"NOR);

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


