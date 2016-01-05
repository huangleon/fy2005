// mind_beast.c

inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
    	set_name("�׿���", ({ "white horse" }) );
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
        "�׿����ԡ������ԣ������쳤�˼���\n",
        }) );
        set("combat_exp", 5000000);
		set_temp("apply/attack", 300);
		set_temp("apply/dodge",300);
		set_temp("apply/damage",200);
	
		setup();
}
void init()
{
	::init();
	add_action("do_xunfu","xunfu");
	add_action("do_ride","ride");
}
string horsedesc()
{
	object me;
	me = this_player();
	if (me ->query("marks/ѱ��_�׿���"))
	{	
		return "ŭ���޴����ˣ���ֻ�����ϣ�ride����Ұ��Ծ��ŭ����";
	}
	return "һƥƤë���׵�Ұ���������ڵ�����ɱ��ţ���֪�Ƿ����ѱ����������������\n";
}


int do_xunfu(string arg)
{
	object me;
	me = this_player();
	
	if (arg != "�׿���" && arg != "white horse" && arg != "Ұ��")
	{	
		tell_object( me, "����Ҫѱ��ʲô��\n");
		return 1;
	}
	
	if (me->query("marks/ѱ��_�׿���"))
	{
		tell_object(me, "�׿���������߲�����ȥ���ǳ����ˡ�\n");
		return 1;
	}
	
	message_vision("$N��˻һ������β̤�㣬���߿񱼣�Ӳ��Ҫ��$n������������ \n",this_object(),me);
	if (me->query_skill("dodge",1)>=50 
		&& me->query("kar")>=(20+random(10))
		&& me->query_skill("animal-training",1)>=100)
	{
        message_vision(HIC"$n����ץס���ף�����$N������������̩ɽ�㸽������\n "NOR,this_object(),me);
        message_vision("$N���ڰ�����������ѱ���ش��Ŵ�������\n$n�����������$N��ͷ��������Ծ��������\n",this_object(),me);
		me->set("marks/ѱ��_�׿���",1);
	}else
	{
		message_vision("$n���ڲ�֧����$N����ˤ��������\n",this_object(),me);
		me->unconcious();
	}
	return 1;
}

int do_ride(string arg)
{
	object me, room;
	me = this_player();
	
	if (arg != "�׿���" && arg != "white horse" && arg != "Ұ��")
	{	
		tell_object( me, "����Ҫ��ʲô��\n");
		return 1;
	}
	
	if (!me->query("marks/ѱ��_�׿���"))
	{
		message_vision("�׿���˻һ����������$n�Ż����ŵص��˼�����\n",me);
		return 1;
	}
	
	if (me->is_busy())
	{
		tell_object(me,"��������æ��\n");
		return 1;
	}
	
	message_vision(HIC"\n$n�����������쳤Хһ������������˫�ȼн���������һ�ޡ��� ��\n\n"NOR,this_object(),me);
	message_vision(HIW"
$N���Ծ����һ���������ҡ���Խ������һ����̬�����ƣ�����ĺ���ë 
��ɽ�������ɵ�Ʈ����������пգ�������ﻮ��һ�������Ļ��ߣ��������� 
Զ����Ũ��� \n\n"NOR,this_object(),me);
	if (REWARD_D->riddle_check(me,"����ŭ��") == 1
		&& !REWARD_D->check_m_success(me,"����ŭ��"))
	{
		me->perform_busy(2);
		room = find_object(__DIR__"obj/horseback");
		if (!room) room = load_object(__DIR__"obj/horseback");
		if (me->move(room))
			call_out("do_riding",2,me,environment(me),room, 2 );
		else
			tell_object(me," BUG, please report to wizard, no room.\n");	
		this_object()->move(VOID_OB);
	}	
	else
	{	
		me->move("/d/guanwai/nujiang");
		message_vision("$N�������󣬳��Ű׿�����������\n",me);
		message_vision("$NԾ�������׿���̤���ȥ��\n",me);
	}
	return 1;
}

string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = load_object(room);

	str = HIR BLK"\n���߷����������׿������վ�������Ϸɱ���\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),

	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}


void do_riding(object me,object room,object env,int count)
{
	object room1;
	
	string *msg = ({
		"�׿�����һ�������ʱ����û�зŻ��Ų���
	
	���߷������������ϰ������ƣ���Ҳ��֪�����ںδ���ֻ�����ر�ס����\n",
	
		"view/d/guanwai/shudao1",
		
		"view/d/guanwai/shudao1",
		
		"view/d/guanwai/shudao1",
		
		"\n\n
�׿���Խ��Խ�죬����Խ��Խ�ߣ�
	
��ǰŨ���ɢ��һ��һ�����ѱ�������֮�ϡ�
		
�׿���߾�ȫ�����Ծ�𣬵�����������������˻һ����׹��ŭ����
	
��׹���һɲ�ǣ��׿���󱳹���������ţ������һ˿�������㵯��\n",
	
	});

	if (!me || !env)
		return;
	if (!room)	
	{
		room = load_object(AREA_GUANWAI"yuema");
		tell_object(me,CYN"\n�׿���һ��񱼣����ڽ��������Ų�����������������\n\n"NOR);
		me->move(room);
		destruct(env);	// destruct used carpet
		return;
	}
	if (count < sizeof(msg))
	{
		if (msg[count][0..3]=="view") // view room.. 
			message_vision(view(msg[count][4..sizeof(msg[count])-1]),me);
		else
			message_vision(WHT""+msg[count]+"\n"NOR,me);
		count ++;
		call_out("do_riding",2,me,room,env,count);
	}
	else
	{
		message_vision(HIR"

���ʧɫ�����ǣ�һ�ж��Ѿ�̫���ˣ�

ˮ�����ף�ˮ����飬���ؿ�Խ��Խ�ƣ���Ҳ�޷�͸��������

������������

\n"NOR, me);		
		room1 = find_object(AREA_GUANWAI"river");
		if (!room1) room1 = load_object(AREA_GUANWAI"river");
		me->unconcious();
		me->move(room1);
		destruct(env);	
		destruct(this_object());
		return;
	}
}


