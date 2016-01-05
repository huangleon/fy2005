// yangfan.c

inherit NPC;

#include <ansi.h>
int answer_shanliu();

void create()
{
	set_name("����", ({ "old monk","monk" }) );
	set("gender", "����" );
	set("age", 78);
	set("title", YEL"���º���"NOR);
	set("long",
"���Ǹ�����ȥ���ϵĺ��У��������ֵģ�Ц������ֱ�ͻ�����һ�����շ���ǰ��
���˸�ľ�㡣\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "�����������������Ҫ�����¾ٷ�����֮ʿ��������ɽ��֮�У�Ϊ���²���ı����\n",
            "�������˿ڳ�����ҡҡͷ������ϧ����ϧ���ѵ���û��һ������ͨ��ɽ���Ŀ���ô��\n",
            "��������ľ�㣬�૵����Ҳ��������˭����������в���Ϳ��˭��Ϳ��\n",
            "����Ц����ɽ���޴����ڣ���Ϊ��ԭ������ÿ������֮ʿ�����С�\n",
    }) );
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 30);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);

	set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        
        set("inquiry",	([
        	"shanliu" : (: answer_shanliu:),
        	"ɽ��"	: (: answer_shanliu:),
		"��ɽ��": (: answer_shanliu:),
        	]) );
	setup();
        carry_object("obj/armor/cloth")->wear();

}

void init()
{
	object ob;
	::init();
	add_action("do_answer","answer");
	add_action("do_kill","kill");
	if( interactive(ob = this_player()) && !is_fighting() )
	{
          remove_call_out("greeting");
          call_out("greeting", 1, ob);
     }
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	//if shanliu dizi already, do nothing
	if(mapp(ob->query("organization")) && (string)ob->query("organization/org_name")=="ɽ��" )
		return;
	if (ob->query("��ɽ��/�������") && !ob->query_temp("��ɽ��/ȡ�˲�") && !ob->query("��ɽ��/ȡ���˲�"))
	{
		message_vision(HIY"$N΢΢��$nЦ�����������������õ��ֿ��鿼��ʩ���ɣ�\n"NOR,this_object(),ob);
	}
}
int do_answer(string arg)
{
	object me,letter,taoist,xiucai;
	
	me=this_player();
	if(me!=query("answering_person"))
		return 0;
	if(arg=="no")
	{
		message_vision(CYN"$N��$n˵������Ȼ��ˣ�ƶɮҲ��ǿ����ȥ�ɡ�\n"NOR,this_object(),me);
		delete("answering_person");
		return 1;
	}
	if(arg=="yes")
	{
		this_object()->heart_beat();
		if(taoist=present("poor taoist",environment()))
			taoist->heart_beat();
		if(xiucai=present("xiucai",environment()))
			xiucai->heart_beat();
		message_vision(HIW"$N��ɫ���صض�$n˵���������з�ټ��ţ����뽫֮����ƽ���ͽ���
ȥ�����µ�ɽ���е�ţ�������ϰ塣����˽�Բ𿴣��мǡ���\n"NOR,this_object(),me);
		letter=new(__DIR__"obj/letter");
		letter->move(me);
		letter->set("������",me);
		me->set_temp("ɽ��/����",1);
		delete("answering_person");
		return 1;
	}
	return 0;
}

int answer_shanliu()
{
	object me;
	
	me=this_player();	
	if(mapp(me->query("organization")) && (string)me->query("organization/org_name")=="ɽ��" )
	{
		say("����������ŵ���������������������ʩ���ʺ�\n");
		return 1;
	}
	if (me->query("��ɽ��/�������"))
	{
		command("pat "+me->query("id"));
		message_vision("$N΢΢��$nЦ����������,���ѹ�������һ����.\n",this_object(),me);
		return 1;
	}
	if (!me->query_temp("ɽ��/ƫ��"))
	{
		return 0;
	}
	if(me->query("combat_exp")<1000000||me->query("score")<20000)
	{
		message_vision(CYN"$N̾�˿�������$nҡ��ҡͷ��\n"NOR,this_object(),me);
		return 1;
	}
	if(me->query("ɽ��/ʧ��")&&(me->query("ɽ��/ʧ��")+86400>time()) || me->query("����/once"))
	{
		message_vision(HIG"$N˵����������������ɽ���ǲ�������ġ���\n"NOR,this_object());
		return 1;
	}
	if (me->query_temp("��ɽ��/�����",1))
	{
		message_vision("$N��ɫһ������ʩ�����������ǿ�����ؤ��\n",this_object());
		return 1;
	}
	if(random(5))
		this_object()->ccommand("hmm");
	else
	{
		message_vision(HIW"$N��ɫ���ص�ע����$n���ƺ�Ҫ��$n������\n"NOR,this_object(),me);
		call_out("verifyJoin",2,me);
		//this_object()->set("answer_ask",me);
	}
	return 1;
}

void verifyJoin(object me)
{
	//object xiucai,taoist;
	if( !me || environment(me) != environment() ) return;
	message_vision(
HIW"$N��Ĭ�˺ܾòŻ�������ɽ����һȺ�ˣ� ׼ȷ��˵��һȺ���ѣ����ǵ���Ȥ
ֻ��һ�����µ������� \n"NOR,this_object());
	message_vision(
HIW"$N�����$n����Ҫ����ɽ��������Ҫ�С����塹�������ɣ����·���и�����
������Ĳ��ˣ���ʩ���ȱ�Ϊ������������ɣ�ȥ�ɣ� \n"NOR,this_object(),me);
		me->set_temp("��ɽ��/�����",1);
	return;
}


int do_kill(string arg)
{
	object xiucai,me,taoist;

	me=this_player();
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
	{
		me->set("ɽ��/ʧ��",time());
		if(xiucai=present("xiucai",environment()))
			xiucai->kill_ob(me);
		if(taoist=present("poor taoist",environment()))
			taoist->kill_ob(me);
	}
	return 0;
}

void die()
{
	object killer;
	
	killer=query_temp("last_damage_from");
	if(killer)
		killer->set_temp("ɽ��/killmonk",1);
	::die();
}
