// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    	set_name("һ��", ({ "master yi", "master"}) );
    	set("nickname", HIM "����"NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "����" );
    	set("reward_npc", 1);
		set("difficulty", 5);
    
    	set("age", 64);
    	
		set("combat_exp", 1300000);
    	set("cor",30);
    	set("attitude","friendly");
    
    	set("long","���ֵ�ʮ�˴����ϣ�ר�Ŵ������ֽ���书��\n"	);
    	create_family("������", 18, "����");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"ɳ��","ɮ��","�޺�","���","����","��ɮ","��ʦ",
		"����","���ó���","����Ժ����","��������","����Ժ����",
		YEL"����Ժ����"NOR,YEL"������"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		
    	set("class","shaolin");
    	
	set_skill("move", 140);
	set_skill("dodge", 140);
	set_skill("unarmed",140);
	set_skill("puti-steps",140);
	set_skill("dabei-strike",140);
	set_skill("zen",130);
	set_skill("chanting",140);
	set_skill("xiaochengforce",140);
	set_skill("parry",140);
	set_skill("foreknowledge",100);
	set_skill("perception",100);
	
	set_skill("force", 160);
	set_skill("literate", 100);
	
	set_skill("axe",150);
	set_skill("wuche-axe",150);
	set_skill("staff",150);
	set_skill("fumostaff",150);
	set_skill("blade",150);
    set_skill("lianxin-blade",150);
	set_skill("liuxing-hammer",150);
    set_skill("hammer",150);
	set_skill("duanhun-spear",150);
	set_skill("spear", 150);
	
	map_skill("axe","wuche-axe");
	map_skill("spear","duanhun-spear");	
	map_skill("staff","fumostaff");
	map_skill("parry","fumostaff");
	map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
	
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
	    	(: perform_action, "unarmed.qianshouqianbian" :)
	}) );
	setup();
	carry_object(__DIR__"obj/bigdan.c");
	carry_object(__DIR__"obj/monk20_cloth")->wear();

}

void attempt_apprentice(object me)
{
	if( me->query("class") == "shaolin" && me->query_temp("won_master_di")){
		command("smile");
        	command("recruit " + me->query("id") );
        	return;
    	} else {
		command("shake");
    	}
}



int accept_fight(object me)
{
        if( is_fighting() )
		command("say ���ж�Ϊʤ��ȥ�����ڵĹ�ɮ�����ɣ�\n");
		
        if(me->query("family/family_name") == query("family/family_name") &&
	   	me->query("family/master_id") == query("id"))
        {
        	if( query("gin") * 100 / query("max_gin") >= 90
			&& query("kee") * 100 / query("max_kee") >= 90
			&& query("sen") * 100 / query("max_sen") >= 90 )
		{
        	       	if (me->query_skill("zen",1) >= 125) {
        			message_vision("$N��ʣ�µ�"HIR"�󻹵�"NOR"�Ե�ǬǬ������\n"
                       				HIR "$N��������һ�������˹���ҩ��������\n"NOR,
                       				this_object());
        			me->set_temp("marks/fi_m_18",1);
        			command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
        			return 1;
        		}
        		command("say ͽ�������������Ϊ̫ǳ��������ɲ��а���\n");	
        		tell_object(me,"����125��������\n");	// 1.2M
        			
        	} else
        		command("say �ã������������Ĵ�����������\n");
        }	
        else
        {
        	command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
    	if (loser->query_temp("marks/fi_m_18")) {
        	command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
			loser->delete_temp("marks/fi_m_18");
		}
    	else 	
    		command("say �����ӷ�\n");
}

void lose_enemy(object winner)
{
    	if(winner->query_temp("marks/fi_m_18")) {
    		command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
    		winner->set_temp("won_master_yi",1);
    		winner->delete_temp("marks/fi_m_18");
    	}
    	else 
    		command("say �����ӷ�\n");
        
}

void check_answer(object me)
{

	if (objectp(me))
	{
		me->delete_temp("inask");
		if (present(me,environment(this_object())))
		{
			message_vision("$N��ĥ����÷֦����$n̾���������㻹δ������\n",this_object(),me);
		}
	}
}

int accept_object(object who, object ob)
{
	if (ob->name() == "���ϵ�÷֦"){
		if(who->query("marks/����_��ڳɹ�")) {
			message_vision("$N����ӹ�÷֦����ϸ�ۿ���һ�������̧ͷ���˿�$n��������ʧ��Ե��\n", 
					this_object(), who);
			message_vision("�����������������㼴�������ĵ��޹ҡ��ҷ�ȱ���\n", this_object());
			return 1;
		}
		if (who->query("marks/����_��_÷֦") && !who->query("marks/����_��_л����")&& who->query("class")=="shaolin"){
			message_vision("$N����ӹ�÷֦����ϸ�ۿ���һ�����\n",this_object());
            		message_vision("$N���󽣾�������÷֦�ϿڵĽ��Ʊ���һ�н����� \n\n",this_object());
			message_vision("$nֻ������һ�н�������ƽƽ������Ȼ�����������һ�� 
�紵÷֦����$N����������ͣ�����ݷ�����һ��������𶯡� \n\n",this_object(),who);
			message_vision("$N�ֳ�÷֦������΢Ц����$n��������������򣿡�(answer yes/no) \n",this_object(),who);
			add_action("do_answer","answer");
			who->set_temp("inask",1);
			call_out("check_answer",120,who);
		} else {
			message_vision("����÷֦�ĶϿڽ��ۣ�$N�����̧��ͷ���Ե�˵����ƣ��ͱ��ˡ� 
���ҷ�ȱ�����$N̾��������һ����������ֻ�л������������\n ",this_object());
		}
		return 1;
	}
	return 0;
}

int do_answer(string arg)
{
	object me;
	me = this_player();
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("��ֻ�ɴ�yes/no \n");
	}
	if (!me->query_temp("inask"))
	{
		return 0;
	}
	remove_call_out("check_answer");
	me->delete_temp("inask");
	if (arg == "yes")
	{
		message_vision("$n˵�����˽�������ף����ӽ��մ��۽硣�� 
$Nҡҡͷ����������һ��֮ѧ������һ�����˽�Ҳ��ֹ�ڴ��ˡ��� ",this_object(),me);

	}else
	{
		message_vision("$n˵�����˽����������������޶ۣ���δ�������򡣡� \n $N˫�ƺ�ʮ���̵����������ӷ𣡡�\n\n ",this_object(),me);
		message_vision("$N��$n˵������������ʮ��������Ħ�ã��õľ��Ǵ��С��˽�һ�������� 
��̫ʦ�壬ǰ��Ħ��ס���޸���ʦ��Ȼ��������ɮ�������������ƴ˽��� 
����Ҳ���޴�̸�𡣡�\n\n",this_object(),me);
		message_vision("$N����һ�أ��ֶ�$n˵�������㽣����Ϊ�Ѿ���ѷ��ʦ����֪�˽�֮�в��������Ը
����������ս��ʮ������ (accept yes/no)\n",this_object(),me );
		add_action("do_accept","accept");
		me->set_temp("inaccept",1);
		call_out("check_accept",120,me);
	}
	return 1;
}

void check_accept(object me)
{
	if (objectp(me))
	{
		me->delete_temp("inaccept");
		if (present(me,environment(this_object())))
		{
			message_vision("$N��$n̾�������������ǲ�Ը������Ҳ������ǿ����ȥ�ɣ���\n",this_object(),me);
			me->delete("marks/����_��_÷֦");
		}
	}
}

int do_accept(string arg)
{
	object me,meizhi;
	me = this_player();
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("��ֻ�ɴ�yes/no \n");
	}
	if (!me->query_temp("inaccept"))
	{
		return 0;
	}
	remove_call_out("check_accept");
	me->delete_temp("inaccept");
	if (arg == "yes")
	{
		message_vision("$N��÷֦����$n�������������ݴ���ʮ����ȥ��ɽׯ��սл���壬�� 
����ȥ������������һ���ľ����㻹Ҫ�ӽ����򡣡�\n",this_object(),me );
		meizhi = new("d/shaolin/obj/meizhi");
		meizhi->move(me);
        me->delete("marks/����_��_÷֦");
        me->set("marks/����_��_��ʮ��",1);
	}else
	{
		message_vision("$Nҡҡͷ������˵���� \n",this_object());
		me->delete("marks/����_��_÷֦");
	}
	return 1;
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}
