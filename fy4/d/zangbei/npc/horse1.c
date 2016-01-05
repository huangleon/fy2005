inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
        set_name("�ƿ���", ({ "yellow horse","horse" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 3);
       //set("long", "һƥƤë������Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n");
	set("long",(: horsedesc :));
        set("max_kee", 3000);
	set("max_gin", 3000);
	set("max_sen", 3000);
		set("int",40);
	set("cor",80);
	set("str",50);
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
   		  "�ƿ����ԡ������ԣ������쳤Х�˼�����\n",
        }) );
        set("combat_exp", 3000000);
	set_temp("apply/attack", 300);
	set_temp("apply/dodge",300);
	set_temp("apply/armor", 100);
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
	if (me ->query_temp("marks/ѱ��_�ƿ���"))
	{	
		return "���ϣ�����壩��ƥ��������ܵ����������һ�ߡ�\n";
	}
	return "һƥƤë����Ӱ������Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n";
}

int do_xunfu(string arg)
{
	object me;
	me = this_player();
	
	if (arg != "�ƿ���" && arg != "yellow horse" && arg != "Ұ��")
	{	
		tell_object( me, "����Ҫѱ��ʲô��\n");
		return 1;
	}
	
	if (me->query("marks/ѱ��_�ƿ���"))
	{
		tell_object(me, "�ƿ���������߲�����ȥ���ǳ����ˡ�\n");
		return 1;
	}
	
	message_vision("$N��˻һ������β̤�㣬���߿񱼣�Ӳ��Ҫ��$n������������ \n",this_object(),me);
	if (me->query_skill("dodge",1)>=50 
		&& me->query("kar")>=(20+random(10))
		&& me->query_skill("animal-training",1)>=100)
	{
        message_vision(HIC"$n����ץס���ף�����$N������������̩ɽ�㸽������\n "NOR,this_object(),me);
        message_vision("$N���ڰ�����������ѱ���ش��Ŵ�������\n$n�����������$N��ͷ��������Ծ��������\n",this_object(),me);
		me->set("marks/ѱ��_�ƿ���",1);
	}else
	{
		message_vision("$n���ڲ�֧����$N����ˤ��������\n",this_object(),me);
		me->unconcious();
	}
	return 1;
}

int do_ride(string arg)
{
	object me,room;
	
	if (arg != "�ƿ���" && arg != "yellow horse" && arg != "Ұ��" && arg!="horse")
		return notify_fail("��Ҫ��ʲô��\n");
	
	me = this_player();
	if (!me->query_temp("marks/ѱ��_�ƿ���"))
		return notify_fail("����Ҫ��ѱ����ƥ����\n");;
	
	message_vision(HIC"$n�����������쳤Хһ������������˫�ȼн���������һ�ޡ��� ��\n\n"NOR,this_object(),me);
	message_vision(HIW"$N���Ծ����һ���������ҡ���Խ������һ����̬�����ƣ��������ë 
��ɽ�������ɵ�Ʈ����������пգ�������ﻮ��һ�������Ļ��ߣ��������� 
Զ����Ũ��� \n"NOR,this_object(),me);
		if (!room=find_object(AREA_RESORT"lake2")) 
			room=load_object(AREA_RESORT"lake2");
		me->move(room);
		message_vision("$N�������󣬳��Żƿ�����������\n",me);
		message_vision("$NԾ�������ƿ���̤���ȥ��\n",me);
	destruct(this_object());
	return 1;
}