// mind_beast.c

inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
    	set_name("�ڿ���", ({ "black horse" }) );
		set("race", "����");
		set("gender", "����");
		set("age", 3);
    
		set("long",(: horsedesc :));
        set("max_kee", 3000);
		set("max_gin", 3000);
		set("max_sen", 3000);
		set("int",40);
		set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
     		"�ڿ����ԡ������ԣ������쳤�˼���\n",
        }) );
        set("combat_exp", 3000000);
		set_temp("apply/attack", 300);
		set_temp("apply/armor", 100);
		set_temp("apply/dodge",300);
		set_temp("apply/damage",200);
		setup();
}
void init()
{
	add_action("do_xunfu","xunfu");
	add_action("do_ride","ride");
}

string horsedesc()
{
	object me;
	me = this_player();
	if (me ->query_temp("marks/ѱ��_�ڿ���"))
	{	
		return "ŭ���޴����ˣ���ֻ�����ϣ�ride����Ұ��Ծ��ŭ����";
	}
	return "һƥƤë������Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n";
}

int do_xunfu(string arg)
{
	object me;
	me = this_player();
	
	if (arg != "�ڿ���" && arg != "black horse" && arg != "Ұ��")
	{	
		tell_object( me, "����Ҫѱ��ʲô��\n");
		return 1;
	}
	
	if (me->query("marks/ѱ��_�ڿ���"))
	{
		tell_object(me, "�ڿ���������߲�����ȥ���ǳ����ˡ�\n");
		return 1;
	}
	
	message_vision("$N��˻һ������β̤�㣬���߿񱼣�Ӳ��Ҫ��$n������������ \n",this_object(),me);
	if (me->query_skill("dodge",1)>=50 
		&& me->query("kar")>=(20+random(10))
		&& me->query_skill("animal-training",1)>=100)
	{
        message_vision(HIC"$n����ץס���ף�����$N������������̩ɽ�㸽������\n "NOR,this_object(),me);
        message_vision("$N���ڰ�����������ѱ���ش��Ŵ�������\n$n�����������$N��ͷ��������Ծ��������\n",this_object(),me);
		me->set("marks/ѱ��_�ڿ���",1);
	}else
	{
		message_vision("$n���ڲ�֧����$N����ˤ��������\n",this_object(),me);
		me->unconcious();
	}
	return 1;
}

int do_ride(string arg)
{
	object me;
	me = this_player();
	
	if (arg != "�ڿ���" && arg != "black horse" && arg != "Ұ��")
	{	
		tell_object( me, "����Ҫ��ʲô��\n");
		return 1;
	}
	
	if (!me->query("marks/ѱ��_�ڿ���"))
	{
		message_vision("�ڿ���˻һ����������$n�Ż����ŵص��˼�����\n",me);
		return 1;
	}
	message_vision(HIC"$n�����������쳤Хһ������������˫�ȼн���������һ��$N���� ��\n\n"NOR,this_object(),me);
		message_vision(HIW"$N���Ծ����һ���������ҡ���Խ������һ����̬�����ƣ�����ĺ���ë 
��ɽ�������ɵ�Ʈ����������пգ�������ﻮ��һ�������Ļ��ߣ��������� 
Զ����Ũ��� \n"NOR,this_object(),me);
	me->move("/d/guanwai/yuema");
	message_vision("$N�������󣬳��źڿ�����������\n",me);
	message_vision("$NԾ�������ڿ���̤���ȥ��\n",me);
	return 1;
}