// Room: sheshenya.c --- by MapMaker

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");

	set("long", @LONG
����һ�μ�խ���յ�ɽ�£���˵�Թ��������ǵõ���ɮ������ȥ֮�������ܰ�
�����ƣ��������ƣ�����Ԩ���޵ס��粻С�ģ�һʧ�����ȥ��ֻ����ʬ�Ƕ��Ҳ�
�����㲻������ȴ�����ľ���ս�����������߰ɣ�ǰ���ƺ�Ҳûʲô·�����ˡ���
����һ��������ʿӭ��������½�ƮƮ���ƺ�Ҫ̤�ն�ȥ��
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"south":__DIR__"fodian",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/liu" :1,
	]) );
	set("coor/x",-5);
	set("coor/y",70);
	set("coor/z",70);
	setup();

}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object liu,me;
	
	me=this_player();
	if(!arg||arg!="down")
		return 0;
	if(liu=present("liu fenggu",this_object()))
	{
		if(!living(liu))
			return 0;
		if(!me->query_temp("ɽ��/jump"))
		{
			message_vision(
HIY"$N��$n΢΢Ц��������̨��ʲô�벻�����أ����û������磬
���Ǳ������ĺá���\n"NOR,liu,me);
		me->add_temp("ɽ��/jump",1);
		}
		else
			message_vision("$N΢΢һЦ��������ס$n��ȥ·��\n",liu,me);
		return 1;
	}
	if(me->query_cor()<20)
		message_vision(
BLU"ɽ���������������ƣ�$N���������µ�������Ԩ���ľ�������������
��ȴ����̱���ڵء�\n",me);
	else
	{
		message_vision(HIW"$Nҧ��ҧ��������һ�գ�����������ȥ��\n"NOR,me);
		tell_object(me,HIR"��ֻ�����߷�����Х������һ�ţ����˹�ȥ��ʲô����֪���ˡ�\n"NOR);
		me->unconcious();
		if(me->query_temp("ɽ��/������"))
		{
			me->move(__DIR__"mishi");
			me->unconcious();
		}
		else
			me->die();

	}
	return 1;
}
			
		
				