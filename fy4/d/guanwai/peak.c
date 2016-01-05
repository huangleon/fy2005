#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", HIW"���µ�һ��"NOR);

	set("long", @LONG
����������µ�һ�塪����������壡��
����Ⱥɽ��Զ���Ĵ��ԭ���ڽ��¡���ɫ�Ĳ��������ڽ����¿������紿��������
����ɫ�ı�������ʶ�һ�����ӷ嶥������˷�����ȥ����Ƕ�ڽ�׵�ɽ���ϡ���
���侢����ѩ���ˣ�����������ɽ�ӣ��������أ�׳־���ƣ�������������֮
�ģ���Х���������ƷŸ衣
LONG);

		set("type","street");
		set("objects", ([
//		__DIR__"npc/champion":1,
        ]) );
        set("exits", ([
        	"return":	"/d/fy/fysquare",
        ]));
        set("no_fly", 1);
        set("outdoors", "guanwai");
		set("coor/x",-50);
		set("coor/y",-100);
		set("coor/z",888);
		setup();
        call_other( "/obj/board/hero_b", "???" );
}



void init()
{
	object me = this_player();
	
	if (!userp(me))	return;
		
	if (!REWARD_D->check_m_success(me,"�µ����")) {
		CHANNEL_D->do_sys_channel("info",sprintf("%s��%s�µ����µ�һ�塪����������壡\n",
					me->name(1),NATURE_D->game_time()));
		REWARD_D->riddle_done(me,"�µ����",50,1);
		me->set("Add_force/�µ����",50);
		me->set("Add_mana/�µ����", 50);
		me->set("Add_atman/�µ����",50);
		
		me->add("max_force",50);
		me->add("max_mana",50);
		me->add("max_atman",50);
		
		tell_object(me,WHT"�������������������������ˣ�\n\n"NOR);
	}	
	
	remove_call_out("greeting");
	call_out("greeting",1);
}




void greeting()
{
	object room,me;
	object *olist;
	mixed *local;
	int i,flag=0;
	local = NATURE_D->getTime(time());
	room = this_object();
	if (local[3] == 6 && local[2] == 6)
	{
		olist = all_inventory(room);
		for(i=0; i<sizeof(olist); i++)
			if (olist[i]->query("void") && !userp(olist[i]))
				flag=1;
		if (!flag && query("create_void") < local[4])
		{
			me = new(__DIR__"npc/void");
			me->move(room);
			set("create_void",local[4]);
		}
	}
	else
	{
		olist = all_inventory(room);
		for(i=0; i<sizeof(olist); i++)
			if (olist[i]->query("void") && !userp(olist[i]))
				destruct(olist[i]);
	}
	remove_call_out("greeting");
	call_out("greeting",60);
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

int valid_leave(object me, string dir){
	if (userp(me))
		message_vision(WHT"$N������Х�������ȥ����ʧ���Ƽ䡣\n\n"NOR, me);
	return ::valid_leave(me,dir);
}