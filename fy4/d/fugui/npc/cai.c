// ���� disabled for now due to bugs -- Silencer

#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;

int test_dart();

void create()
{
        set_name("����", ({ "cai shu","cai","caishu" }) );
        set("gender", "����" );
        set("age", 52);
        set("richness",5000000);

        set("no_arrest",1);
        set("long",
		"һ���ֺǺǵ����ڹ�̨�������۾��������ӵ�С��ͷ��\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");

        set("chat_chance", 2);
		set("chat_msg", ({
       		"��������ţ�����·����ʣ�Ƿ�˸����Ӽ�ʮ��Ǯ���Ͳ�֪�㵽��ȥ����ˡ�\n",
//       		"����˵�������˧Ҫ���˻��ڣ�Ӧ���Ƽ�˭ȥ��������񣨣�������أ���\n",
        }) );
        set_skill("unarmed", 100);
        set_skill("dodge", 130);
		set_skill("force", 100);
		set_skill("yue-strike",40);
		set_skill("hammer",100);
		set_skill("liuxing-hammer",10);
		
		map_skill("hammer","liuxing-hammer");
		map_skill("unarmed","yue-strike");
        
/*      set("inquiry", ([
        	"mission" : (: test_dart :),
			"����" : (: test_dart :),
        ]) );*/

        setup();

		set("mutant_rate",20);	// 20% chance
		set("mutant_name",1);	// Change Name?
		mutant();

		carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/goldabacus")->wield();
}

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
		add_action("do_loan","loan");
//		add_action("do_accept", "accept");
}

void reset(){
	set("richness",5000000);
}

/*
int test_dart()
{
	object me;
	
	me=this_player();
	if (random(100)>50  || query("marks/gived") )
	{
		set("marks/gived",1);
		command("say ���Ѿ��ҵ�Ѻ�ڵ�Ӣ���ˣ��´ΰɣ�");
		return 1;
	}
	else
	{
		me->set_temp("marks/caiasked",1);
		command("say ����������Ҫ��һǧ����������Ѻ�ģ����Ը����ܣ�(accept mission)");
		return 1;
	}
}

int do_accept(string arg)
{    
	object obj;
	object me;
	if (arg != "mission") 
		return notify_fail("ʲô��\n");
		
	me=this_player();
	
	if (! me->query_temp("marks/caiasked"))
	{
		return notify_fail("ʲô��\n");
	}
	
	if (me->query("marks/���廤��"))
	{
		command("heihei");
		command("say ��λ"+RANK_D->query_respect(me)+"��Ϊ��Ҫ��ʵ���ϴε�����������𣿣�");
		return 1;
	}
	
	if (me->query("combat_exp")<1500000)
	{
		command("heihei");
		command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(me)+"�ƺ������ʸ�");
		return 1;
	}
	
	if (!intp(me->query("deposit")) || me->query("deposit")<10000000)
	{
		command("hmm");
		command("say ��λ��͵�������Ŀ��С���ҿ���λ"+RANK_D->query_respect(me)+"û���㹻�Ĵ������Ѻ��");
		return 1;
	}
	
	if ( query("marks/gived") )
	{
		command("sigh");
		command("say �������ˣ��Ѿ����˽���������ˡ�");
		return 1;
	}

	set("marks/gived",1);
	me->set("marks/���廤��",1);
	me->set_temp("marks/�Ƽ�",1);
	command("say �ã��ҾͰ����Ƽ������˧��ǧ���������Ѿ�������˻��Ͽ۳��ˡ�");
	me->add("deposit",-10000000);
	obj=new(__DIR__"obj/letter");
	if(obj)
		obj->move(me);
	message_vision("$N�ó�һֽ�Ƽ��Ÿ�$n��\n",this_object(),me);
	command("say ��������ֽ��ȥ���˧����ɣ�\n");
	return 1;
}
*/