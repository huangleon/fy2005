#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLU"��������999"NOR);
  set ("long", @LONG

LONG);
		set("objects", ([
			__DIR__"npc/dc" :3,
	]) );
	set("no_fight",1);
	set("no_fly",1);
  	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{       
	object ob;
	if ( interactive(ob = this_player())) 
		call_out("greeting", 1, ob);
}

void greeting(object me)
{
	object room;
	string tc;
	if (me->query_temp("annie/laputa_up"))
		tc=__DIR__"station";
	else
		tc="/d/fy/station";
	room=find_object(tc);
	if (!room)
		room=load_object(tc);
	tell_object(me,HIY"���������л�������վ̨��ͣ�¡�\n"NOR);
	me->set_temp("annie/laputa_up",0);
	me->set_temp("annie/laputa_up",0);
	tell_object(me,CYN"\n�㲽�µ��У���������˿�����\n\n"NOR);
	me->move(room);
	message_vision("$N���˹�����\n"NOR,me);
	return;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
