
#include <login.h>
#include <ansi.h>

//function definition
int start_test();

inherit NPC;


mapping *question_list=({
	([	"question": "Q1: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",10,}),
				({"B: woman",10}),	
				({"C: Both",10,}),
				({"D: Neither",10,})
		}),
	]),
	([	"question": "Q2: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",20,}),
				({"B: woman",20}),	
				({"C: Both",20,}),
				({"D: Neither",20,})
		}),
	]),
	([	"question": "Q3: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",30,}),
				({"B: woman",30}),	
				({"C: Both",30,}),
				({"D: Neither",30,})
		}),
	]),
	([	"question": "Q4: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",40,}),
				({"B: woman",40}),	
				({"C: Both",40,}),
				({"D: Neither",40,})
		}),
	]),
});


string get_question(int i)
{
	int j;
	string temp = question_list[i]["question"] + "\n";
	for (j=0;j<4;j++)
	{
		temp = temp + question_list[i]["answer"][j][0] + "\n";
	}
	return temp;
}


void create()
{
	set_name("������", ({ "news man","man"}) );
	set("title",YEL "������֪"NOR);
	set("long", "ֻҪ��������ȴ���������⣬����ͭ����ѽ��\n");
	set("gender", "����");
	set("age", 70);
	set("no_fight",1);
	set("combat_exp", 9000);
	set("score", 0);
	set("inquiry",([
    //	"����" : (: start_test :),
    //	"test" : (: start_test :),
    ]) );
	set ("no_arrest",1);
	set("in_test",0);
	setup();
}


void init()
{
	::init();
	//if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_killing", "kill");
}

start_test()
{

	if(query("in_test")) 
	{
		message_vision("���������⣬��������һ�֡�\n", this_player());
		return 1;
	}
	set("in_test", 1);
	command("say ���Կ�ʼ������");
	this_player()->set_temp("score", 0);
	this_player()->set_temp("answer_questions", 0);
	this_player()->set_temp("num_question", random(sizeof(question_list)));
	this_player()->set_temp("in_ask", 1);
	ask_question();
	add_action("do_answer", "answer");
	return 1;
}

void clear_temp(object me)
{
	me->delete_temp("score");
	me->delete_temp("answer_questions");
	me->delete_temp("num_question");
	me->delete_temp("in_ask");
}

void ask_question()
{
	message_vision( get_question(this_player()->query_temp("num_question")) + "\n",this_object());
	this_player()->set_temp("in_ask", 1);
	call_out("check_status", 60, this_player());
}

void give_result()
{
	object me = this_player();
	set("in_test", 0);
	message_vision("You have finished your test and your score is " + me->query_temp("score") + "\n", this_player());
	clear_temp(me);
}

int do_answer(string arg)
{

	object me = this_player();
	
	int	score = me->query_temp("score");
	int	num_question = me->query_temp("num_question");
	int answer_questions = me->query_temp("answer_questions");
	if (!me->query_temp("in_ask"))
	{
		return 0;
	}

	remove_call_out("check_status");
	switch (arg)
	{
	case "a" :
		score = score + question_list[num_question]["answer"][0][1];
		break;
	case "b":
		score = score + question_list[num_question]["answer"][1][1];
		break;
	case "c":
		score = score + question_list[num_question]["answer"][2][1];
		break;
	case "d":
		score = score + question_list[num_question]["answer"][3][1];
		break;
	default:
		return notify_fail("You have to answer a,b,c,d \n");
		break;
	}
	
	num_question = (num_question+1) % sizeof(question_list);
	answer_questions++;
	me->set_temp("score", score);
	me->set_temp("answer_questions", answer_questions);
	me->set_temp("num_question",num_question);
	me->set_temp("in_ask", 0);
	if ( answer_questions >= 3 )
	{
		give_result();
		
	}
	else
	{
		ask_question();
	}

	return 1;
}

void check_status(object ob)
{
	if ( !ob )
	{
		set("in_test", 0);
	}
	else if( ob->query_temp("in_ask") && environment(ob) == environment() )
	{
		message_vision ("�����ǵ�ʱ��Ҳ̫���˰ɣ� \n", ob);
		message_vision ("��������$N���˳�ȥ�� \n", ob);
		ob->move("/d/fy/ecloud5");
		//clear_temp(ob);
	}
}

void remove_frozen(object me)
{
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
	message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR, me);
}

int do_killing(string arg)
{
	object target = select_opponent();
	if ((arg == "news man") && query("in_test") )
	if (query("in_test"))
	{
		command("say ������������˵��ҵ���\n");
		message_vision(HIC "������һ���֣����������ǵ����˸���ŵ�����������\n",target);
		message_vision(HIW "����ĺ�����Χ��$N��ȫ����$N���۳ɱ��飡", target);			
		target->set_temp("disable_inputs",1);
		target->set("disable_type",HIW "<������>"NOR);
		target->set_temp("is_unconcious",1);
		seteuid(ROOT_UID);
		target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :), 10);
		message_vision("$N������һ������ \n", target);
		message_vision(HIY "������һ�ŰѶ��ɴ�����$N�ߵ�����ϡ�\n"NOR,target);
		target->move("/d/fy/ecloud5");
		message_vision(HIY "���һ���������ɴ�����$N�������˳�����\n"NOR, target);
		return 1;
	}
	else
	{
		return 0;
	}
}
