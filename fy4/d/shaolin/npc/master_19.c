// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    	set_name("��ƥ", ({ "master di", "master"}) );
    	set("nickname", HIY "��Ե" NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "����" );
    	set("reward_npc", 1);
	set("difficulty", 3);
    
    	set("age", 64);
    	set("per", 35);
    	
	set("combat_exp", 1100000);
    	set("attitude","friendly");

    	set("long", "���ֵ�ʮ�Ŵ����ϣ�ר�Ŵ��������޺��书��\n");
    	create_family("������", 19, "����");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"ɳ��","ɮ��","�޺�","���","����","��ɮ","��ʦ",
		"����","���ó���","����Ժ����","��������","����Ժ����",
		YEL"����Ժ����"NOR,YEL"������"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		
    	set("class", "shaolin");
    
    	set_skill("move", 120);
    	set_skill("dodge", 120);
    	set_skill("literate", 100);
    	set_skill("unarmed",120);
    	set_skill("puti-steps",120);
    	set_skill("dabei-strike",120);
    	set_skill("zen",120);
    	set_skill("chanting",120);
    	set_skill("xiaochengforce",120);
    	set_skill("parry",120);
    	
		set_skill("foreknowledge",100);
		set_skill("perception",100);
 
 		set_skill("force", 140);
 
  		set_skill("spear", 150);
    	set_skill("duanhun-spear",150);
  		set_skill("staff",150);
    	set_skill("fumostaff",150);
    	set_skill("blade",150);
    	set_skill("lianxin-blade",150);
		set_skill("liuxing-hammer",150);
    	set_skill("hammer",150);
    
    	map_skill("spear","duanhun-spear");
    	map_skill("hammer","liuxing-hammer");
    	map_skill("staff","xingyi-stick");
    	map_skill("parry","lianxin-blade");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "dabei-strike");
    	map_skill("blade","lianxin-blade");
    
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    
    	setup();
    	carry_object(__DIR__"obj/monk21_cloth")->wear();

}

void attempt_apprentice(object me)
{
    	if(me->query("class") == "shaolin" && me->query_temp("won_master_meng"))
    	{
		command("smile");
        	command("recruit " + me->query("id") );
        	return;
    	}
    	else
    	{
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
        	       	if (me->query_skill("zen",1) >= 120) {	// 660k
        			command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
        			me->set_temp("marks/fi_m_19",1);
        			return 1;
        		}
        		command("say ͽ�������������Ϊ̫ǳ��������ɲ��а���\n");	
        		tell_object(me,"����120��������\n");		
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
    	if (loser->query_temp("marks/fi_m_19")) {
    		command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
    		loser->delete_temp("marks/fi_m_19");
    	}
}
void lose_enemy(object winner)
{
    	if (winner->query_temp("marks/fi_m_19")) {
    		command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
    		winner->delete_temp("marks/fi_m_19");
    		winner->set_temp("won_master_di",1);
    	}
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}
