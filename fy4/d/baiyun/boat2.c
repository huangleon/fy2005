#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "һҶС����");
	set("long", @LONG
һҶ��ӯ��С�ۣ�������������������죩��\n
LONG
	   );
	set("no_fight",1);
	set("no_magic",1);	
	set("no_fly",1);	
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",-20);
	setup();	   
}

void init()
{
    add_action("do_sail","sail");
}

void boat_sail(int counter,object me)
{
    if (me->query_skill("dodge",1) < 30 )
		{
		  message_vision(HIB"һ�����˴�����$N���²��ȣ��������֮�У�����\n"NOR,me);
		  me->delete_temp("counter");
		  me->move(__DIR__"seabutton1");
		  return;
		}
	switch (counter)
		{
		  case 1:
		  tell_object(me,HIC"��ˮ�ڽ���ʱ��������ʱ���ͳ���ʱ����ӿ��ʱ����˳������
��ȥ��������ӣ��ޱ��޼ʣ�һƬ���ɡ��·���Զû�о�ͷ��\n"NOR);
		  break;
	                 
		  case 2:
		  tell_object(me,HIC"�ƻ��ȥ����ҹ���٣�ǰ������ãã��ҹ��̧ͷ���죬������
�����죬��˸���ѡ��������������������˷�������ҹ���ţ�
����������̫����Ҫ����\n"NOR);
		  break;

		  case 3:
		  tell_object(me,HIC"����ʱ�֣�����֮����Լ���ֳ�½�ص�Ӱ�ӣ����÷�����\n\n"NOR);
		  me->delete_temp("counter");
		  tell_object(me,HIY"��ƴ���������˼��£����ڵ��˰��ߡ��㻳�ż����������뿪С����̤��½�ء�\n"NOR);
          me->move("/d/manglin/seaside");
		  break;
		} 
	return;
}

int do_sail(string arg)
{   
	object me;
	me = this_player();
	if( !arg || (arg != "north") ) 
	return notify_fail("��½�ڱ��ߣ��򱱻��ɡ�(sail north)\n");
	if (me->is_busy())	return notify_fail("��������æ��\n");
		
	if( arg=="north" ) 
	{
		me->add_temp("counter", 1);
		write("��������С��������ȥ....\n");
		me->perform_busy(1);
		call_out("boat_sail",0,me->query_temp("counter"),me);
    }
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
