// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("�����", ({ "xiucai" }) );
	set("gender", "����" );
	set("age", 68);
	set("title", GRN"��������"NOR );
	set("long",
"���Ǹ�����С�ڵ��������,�ƺ��Ѿ������Щҡҡ��׹,Ҳûʲô���ڵĵط�,��ż��
΢��˫��,���۹�ȴϬ����硣�������ű�����,���ﲻͣ�������ʲô��\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "����ſ��鿴��ü��ɫ�裬ͻȻ���ص�һ�����ӣ�����Ц������һ�����ӷ�����һ
���캥����һ׵��Ȼ���У������Ծ���ض������񡭡�ʹ��ѽʹ�죬������һ��ס�\n",
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
          call_out("greeting", 1, ob);
     }
}

int do_answer(string arg)
{
	object letter, box,me;
	me=this_player();
	if (!me->query_temp("xiucai_ask"))
	{
		return 0;
	}
	if (arg !="yes" && arg!="no")
	{
		return notify_fail("��ֻ���Իش�yes��no\n");
	}
	me->delete_temp("xiucai_ask");
	if (arg = "yes")
	{
		message_vision(
HIR"$N��˼��Ƭ�̣�֣�صص����ұ����ˣ�����Ϊ��������Ϊ���ң�Ը��ɽ���� \n"NOR,me);
		message_vision(
HIC"\n$N����Ц����ʹ�찡ʹ�죡������һ��ټ��ţ����뽫֮����ƽ���ͽ���
ȥ�����µ�ɽ���е�ţ�������ϰ塣����˽�Բ𿴣��мǡ� \n"NOR,this_object());
		letter = new(__DIR__"obj/letter");
		letter->set("�Ͷ�����",me);
		letter->move(me);
		message_vision("$N�ݸ�$nһ����\n\n",this_object(),me);
		message_vision(
HIC"$Nš���ƺ�«����ཹ�ེ��˼�����ֵ������������̴ľ������ɽ��������
���ڽ����������ྭӪļ����������Ʊ������������һ�������߸������Ϲ���\n"NOR,this_object());
		box = new(__DIR__"obj/tanmubox");
		box->set("�Ͷ�����",me);
		box->move(me);
		message_vision("$N�ݸ�$nһ��̴ľ�С�\n\n",this_object(),me);
		me->set_temp("��ɽ��/�Ͷ���",1);
	}
	else
	{
		message_vision("$N������ã���������⡣����������������ϸ˼��һ���� \n",me);
		me->delete("��ɽ��/ȡ���˲�");
		me->delete("��ɽ��/�������");
	}
	return 1;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("��ɽ��/�������") && ob->query("��ɽ��/ȡ���˲�"))
	{
		if (ob->query_temp("��ɽ��/�Ͷ���"))
		{
			message_vision("$N��$n���������͵���û�У�\n",this_object(),ob);
		}else
		{
			message_vision(
HIC"$Nü��ɫ���$n�������ٿ��ǿ��ǣ�һ��ɽ���������ް���֮���ˣ��ܶ���
�飬���۶����ѣ���Σ�գ��㶼�ò��ں�������Ҳ���ں�����ɽ�����ˣ���Ҫ���ǡ����š����֡� \n"NOR,this_object(),ob);
			message_vision(
HIC"���㣬$N����ض���$n��һ��һ�ֵ����������ĵ�ô����ȷ��Ҫ����[ɽ��]ô��
(answer yes or no)\n"NOR,this_object(),ob);
			add_action("do_answer","answer");
			ob->set_temp("xiucai_ask",1);
		}
	}
}

int do_kill(string arg)
{
	object taoist,me,monk;

	me=this_player();	
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
	{
		me->set("ɽ��/ʧ��",time());
		if(taoist=present("poor taoist",environment()))
			taoist->kill_ob(me);
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
	killer->set_temp("ɽ��/killxiucai",1);
	::die();
}
