#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "佻�Ϫ");

	set("long", @LONG
һ���峺���׵�Ȫˮ��ɽ�н����������������д��ӵ��أ�����С���������
�̣�����ɽ��������Ϫˮ�и�ɫ�ͷ׵Ļ�������Ϫˮ���������ʣ�һ�������续��
Ȫˮǳǳ���У��������ϣ��ɿ�����Զ���������ȪˮԴͷ�и�������
LONG);

	set("type","waterbody");
	set("outdoors", "wolfmount");
	set("exits",([
		"southeast":__DIR__"brook4",
		"southwest":__DIR__"brook3",
	]) );
	set("objects",([
		__DIR__"npc/xiaoling":1,
		__DIR__"npc/xiaorou":1,
	]) ); 
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_look", "look");
}


void conch_notify()
{
	object me;
	int lel;
	me = this_player();
	lel = me->query("kar");
	if(random(100) < lel) 
	{
		tell_object(me,"ͻȻһ���������������ƺ���ɢ����ࡣ\n"); 
		REWARD_D->riddle_done(me,"������ɽ",10,1);
		if (!me->query_temp("marks/wolf_blow_conch"))
		{
			me->set_temp("marks/wolf_blow_conch",1);
		}
	}
	else 
	{
		message_vision("�����ã��������ɣ�ʲô��û�з�����\n",me);
	}
	return;
}

int valid_leave(object me, string dir)
{
     if( userp(me) && dir=="southwest" )
     {
        if (me->query_temp("annie/wolf_conch"))
		{
			message_vision("$N���������е�����������˼������ڡ���\n", this_player() );
			tell_object(me,"����ŷ����˲�䣬��������\n"); 
			return 1;
		} else if (me->query_temp("marks/wolf_blow_conch")  ) 
       	{
            tell_object(me,"����ŷ����˲�䣬��������\n"); 
            me->delete_temp("marks/wolf_blow_conch");			
			return 1;
        }    
        
        message_vision("��ǰ�������������Կ���ǰ·��$N���ò�ͣ�½Ų���\n", me);
		return notify_fail("����ֻ�еȵ�����ʱ��ɢ�����ˣ�\n");
		
	}
	else
	{
		return 1;
	}
}



int do_look(string arg)
{
        object 	me;
		me = this_player();
	if( arg == "southwest") 
	{
		message_vision(HIY"$N̽ͷ̽�Ե������Ϸ����˿�������������\n"NOR, me);
		tell_object(me,"�Ǳ�����������ʲô����������\n"); 
		return 1;
	}
	return 0;
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


