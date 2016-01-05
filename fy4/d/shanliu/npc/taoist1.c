// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("���ʿ", ({ "poor taoist","taoist" }) );
	set("gender", "����" );
	set("age", 68);
	set("title", CYN"���ĵ���"NOR);
	set("long",
"����λ���ź������õ��ϵ�ʿ,���Ͽ���ȥȫ�����࣬üë���Ӷ��������ճ����һ��,
�������,��էһ��ȥ,ȴ����Ī���������ɾ����ĸо���\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "���ʿ��ʮ�����컨��Ҷ����ź�����̱�����һ�ң�ܿܿ������˭������ɽ��֮�ѣ�\n",
    }) );
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 30);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);
	set("ALWAYS_ACTIVE",1);
	set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
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
          call_out("greeting", 2, ob);
     }
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("��ɽ��/ȡ���˲�"))
	{
		return;
	}
	if (ob->query("��ɽ��/�������"))
	{
		if (ob->query_temp("��ɽ��/ȡ�˲�"))
		{
			message_vision(
"\n$N΢΢Ц������λ"+RANK_D->query_respect(ob)+"�õ������˲���ô��\n",this_object());
		}else
		{
			message_vision(
HIY"$N�������ף���$nЦ��������ɽ�����͵���ȫ�����Լ����͵�Ҫ���µ���
�ľ��񣬸�������Ҳ�������ǣ�\n"NOR,this_object(),ob);
			message_vision(
HIY"$N����һ���ֶ�$n�����ã��Ǿ�Ҫ������µġ���ʶ���ˣ� \n"NOR,this_object(),ob);
			call_out("test_danshi",3,ob);
		}
	}
	return;
}

void test_danshi(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision(
HIY"$N����Ƭ�̺�,��$n�����ݴ����ڵ���������ȴ�ǵ���������������赣���һ
�������˲᡿��¼�������ڽ����е����ѣ��ƺ������޹�ɽׯ������°�ɽ��
ȡ�أ�����ȡ�أ��⡸��ʶ��һ�أ���Ȼ�͹��ˡ� \n"NOR,this_object(),ob);
	ob->set_temp("��ɽ��/ȡ�˲�",1);
}

int accept_object(object who, object obj)
{
	object xiucai;
	if (obj->query("name")==HIR"�����˲�"NOR)
	{
		if (who->query_temp("��ɽ��/ȡ�˲�"))
		{
			who->delete_temp("��ɽ��/ȡ�˲�");
		}
		message_vision(
HIC"\n$N����Ц�����ã��ã��ã����������˲ᣬ��������һ����֮��\n"NOR,this_object());
		message_vision(
HIC"\n$N������$n�����Ц�����Ǿ�����������ֿ��鿼����ɣ�\n\n"NOR,this_object(),who);
		who->set("��ɽ��/ȡ���˲�",1);
		if (xiucai = present("xiucai",environment()))
		{
			xiucai ->greeting(who);
		}
		return 1;
	}
	return 0;
}

int do_kill(string arg)
{
	object xiucai,me,monk;

	me=this_player();	
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
	{
		me->set("ɽ��/ʧ��",time());
		if(xiucai=present("xiucai",environment()))
			xiucai->kill_ob(me);
		if(monk=present("old monk",environment()))
			monk->kill_ob(me);
	}
	return 0;
}


void die()
{
	object killer;
	
	killer=query_temp("last_damage_from");
	if(killer)
		killer->set_temp("ɽ��/killtaoist",1);
	::die();
}
