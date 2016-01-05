inherit __DIR__"heroine";
#include <ansi.h>
void create()
{
	set_name("���",({"hong er"}) );
	set("long", "��һϮ���£���ͬ���������¡���˫���°���۾���Ц������ʱ�� 
�ͺ�����һĨ��������̸�����ơ� 
\n");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
             "�������̾Ϣһ����������������͵ģ���ʱ��Ȼ�����˱�������\n" ,
        }) );



	::create();
	setup();
	carry_object(__DIR__"obj/white_cloth")->wear();
}
	
mapping* event_list=({});
mapping query_answers(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["question"]==topic)
			return event_list[i];
	return 0;
}

mapping query_events(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["events"]==topic)
			return event_list[i];
	return 0;
}

string *killing_msg=({ 
       HIC"$N����$n���۾���¶��ʹ��֮ɫ����Ȼ����ͷ�����ĵ�˵����Ҳ���ұ� 
    ������ɱ�㣬Ҳ�����������������ġ���\n"NOR, 
       HIR"�����������ĬĬ������$N��ȻЦ��Ц����$n˵����������ɱ�� ���������Լ��Ѿ�������ˡ���\n"NOR, 
       HIC"$N����̾Ϣ��һ����������˵��������룬���ƵĶ�$n����������һ������������һ���ȥ�ˣ��ո�һ�գ��긴һ�꣬����������Ҫ����ʲôʱ��Ϊֹ����\n"NOR, 
       HIY"$N��һ��ƽ�����Ѿ��ӽ�����������$n˵�����±������кܶ��޿��κε� 
�£���ĳһ������У�һ��������֪���Լ������²���Ҳ���ܲ�����ȥ����\n"NOR, 
       HIG"$N��$nǳЦ�������������������Ȼ�������Դ�����ء���\n"NOR, 
       HIB"$N�����������$n��ߣ�������ʣ�������ɱ��$n���𣿡�\n"NOR, 

});

string query_killing_msg()
{
	return killing_msg[random(sizeof(killing_msg))];
}
void init()
{
	object me;
	
	::init();
	me=this_player();
	if(query("killing_person")==me)
	{
		if(!me->query("vendetta/taoyuan")||me->query("vendetta/taoyuan")+10800<time())
		{
			message_vision(CYN"$Nϸϸ������һ��$n��̾�˿�����ת����ȥ��\n"NOR,this_object(),me);
			this_object()->move("/d/fy/church");
			delete("killing_person");
			delete("following_person");
			delete("no_leave");
			return ;
		}
		message_vision(query_killing_msg(),this_object(),me);
		// can adjust honger's level according to player here
		set("combat_exp", (int) me->query("combat_exp") *9/8 );
		kill_ob(me);
	}
}

void die()
{
	object me;
	
	if(me=query_temp("last_damage_from"))
		message_vision(HIG"$NĿ��ͻȻ�ֳ�һ˿Ц�⣬����ã������׽����Ц�⣬����˵������ƣ������Ρ�
$Nת��ƮȻ��ȥ�� $n�Ķ���ֻ��������һ�䡰�һ��ٻ����ġ���\n"NOR,this_object(),me);
	else
		message_vision(MAG"$NĿ��ͻȻ�ֳ�һ˿Ц�⣬����ã������׽����Ц�⣬����˵������ƣ������Ρ�
$Nת��ƮȻ��ȥ�� \n"NOR,this_object());

	this_object()->move("/d/fy/church");
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	if(!me)
		me=query("killing_person");
	set("no_chasing",1);
	call_out("begin_chasing",60+random(60));
}

void unconcious()
{
	die();
}

int begin_chasing()
{ 	
	object me;
	if(!query("chasing_time")||query("chasing_time")+10800<time())
	{
		delete("killing_person");
		delete("following_person");
		return 1;
	}
	if(me=query("killing_person"))
	{ 
		delete("no_chasing");
		return 1;
	}
	call_out("begin_chasing",15+random(15));
	return 1;
}

int do_fighting()
{
	if(query_busy())
		return 1;
	if(!query_temp("daoqian"))
	{
		this_object()->ccommand("perform iron-cloth.bingwantianzhang");
		return 1;
	}	
	switch(random(3))
	{
		case 2:
		this_object()->ccommand("perform tanzhijinghun");
		break;
		
		case 1:
		this_object()->ccommand("perform dodge.yexuechuji");
		break;
	}
	return 1;
}

void heart_beat()
{
	::heart_beat();
	if(is_fighting())
		do_fighting();
}