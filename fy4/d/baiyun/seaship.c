//sinny@fengyun.com
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
int counter;
void create()
{
	set("short", "�󺣴�");
	set("long", @LONG
һ�Ҹ�Φ����̡����õĴ󺣴��������ˮ���أ�������Ȼ�����˻�����װ��Խ
�࣬��������Խ�ȣ�������û�г�������Ҳ�������δ��ġ�ֻҪ��һ�����£��Ϳ���
���㰲ȫ�Ĵ�������ȥ�ĵط��������򣩡�\n
LONG
	   );
	set("no_fight",1);
	set("no_magic",1);
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",-20);
	setup();	   
}

void init()
{
    add_action("do_order","order");
}

int do_order(string arg)
{   
	object me;
	me = this_player();
	if( !arg || (arg!="south" && arg!="���Ƶ�") ) 
	return notify_fail("��Ҫ���Ķ����У�\n");
	if( arg=="south" || arg=="���Ƶ�" ) 
		{ 
		  counter=1;	
                  write("������ϵ�ˮ�ָı亽����ʹ�󺣴����ϱߵİ��Ƶ�ʻȥ....\n");
                  call_out("ship_sail",3,counter,me);
                }
	return 1;
}

void ship_sail(int counter,object me)
{
	switch (counter)
	       {
		  case 1:
		  message_vision(HIC"��ˮ�ڽ���ʱ��������ʱ���ͳ���ʱ����ӿ��ʱ����˳������
��ȥ��������ӣ��ޱ��޼ʣ�һƬ���ɡ��·���Զû�о�ͷ��\n"NOR,me);
		  break;
	                 
		  case 2:
		  message_vision(HIC"�ƻ��ȥ����ҹ���٣�ǰ������ãã��ҹ��̧ͷ���죬������
�����죬��˸���ѡ��������������������˷�������ҹ���ţ�
����������̫����Ҫ����\n"NOR,me);
		  break;

		  case 3:
		  tell_object(me,HIC"����ʱ�֣�����֮����Լ����һ��С�������÷�������С��ȴ
��ʮ�ֹŹ֣�С������������ľ�ɫ����Э��������һ�ֹ���ĸо���\n"NOR);
		  tell_object(me,HIY"�󺣴����ڵ��˰��ߡ��㻳�ż���������̤��С����\n"NOR);
		  me->move(__DIR__"baiyunentrance");
		  break;
	       } 
	if ( counter<3)	call_out("ship_sail",5,counter+1,me);
	else {
	      counter=0;
	      return;
	     } 
}