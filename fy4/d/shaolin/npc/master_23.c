// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
    	set_name("����", ({ "master kong", "master"}) );
    	set("nickname", HIG "��Ϊ" NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "����" );
    	set("reward_npc", 1);
		set("difficulty", 1);
    	set("class","shaolin");
    	set("combat_exp", 100000);
    	set("age", 64);
    	set("per", 35);
    	    
    	set("attitude","friendly");
    	set("long","���ֵڶ�ʮ������ʦ������ר�Ŵ��������׼ҵ����书��\n");
    	set("inquiry", ([
        	"����ǰ" : (: got_me :),
        	"chujiaqian" :  (: got_me :),
        	"leave" : (: leave :),
    		       
        ]) );
    	create_family("������", 23, "����");
    	    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"ɳ��","ɮ��","�޺�","���","����","��ɮ","��ʦ",
		"����","���ó���","����Ժ����","��������","����Ժ����",
		YEL"����Ժ����"NOR,YEL"������"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		
        
    	set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    	
    
    	set_skill("move", 80);
    	set_skill("dodge", 80);
    	set_skill("force", 80);
    	set_skill("literate", 100);
    	set_skill("unarmed",80);
    	set_skill("parry",80);
    	set_skill("puti-steps",80);
    	set_skill("dabei-strike",80);
    	set_skill("zen",60);
    	set_skill("chanting",80);
    	set_skill("xiaochengforce",80);
		set_skill("foreknowledge",80);
		set_skill("perception",80);
    	set_skill("blade", 120);
    	set_skill("lianxin-blade",120);
    	
    	map_skill("blade","lianxin-blade");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "dabei-strike");
    	setup();
    	carry_object(__DIR__"obj/monk22_cloth")->wear();
}


void attempt_apprentice(object me)
{
    	if(me->query("gender") != "����")
    	{
			command("say ���գ����գ���λŮʩ����ذɣ�����ֻ���е��ӡ�\n");
			return;
		}
		else if(me->query("marry") && !me->query("jiebai"))
		{
			command("say ��λʩ������δ����������ذɡ�\n");
			return;
		}	
		else if( me->query_skill("dabei-strike",1)>=15 && 
        		me->query_skill("xiaochengforce",1)>=10 &&
        		me->query_skill("puti-steps",1)>=15 )
    	{
			command("smile");
       		command("recruit " + me->query("id") );
       		return;
    	}
    	else 
    	{
			command("smile");
    	    command("say ��ʦҪ�г��⣬����ȥѧѧ���İɣ�\n");
        	tell_object(me,"���裱������ȴ��֡�������С���ľ������������Ჽ����\n");
        	return;
		}
}

int accept_fight(object me)
{

	if( is_fighting() )
		command("say ���ж�Ϊʤ��ȥ�����ڵĹ�ɮ�����ɣ�\n");
		if(me->query("class") == "shaolin")
        {
        	if( query("gin") * 100 / query("max_gin") >= 90
			&& query("kee") * 100 / query("max_kee") >= 90
			&& query("sen") * 100 / query("max_sen") >= 90 )
		{
			command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
			me->set_temp("marks/fi_m_23",1);
        	return 1;
			
		}
		else
		       	command("say �ã������������Ĵ�����������\n");
			
        }
        else
        {
        	command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        	
        }
        return 0;
}

void win_enemy(object loser)
{
	if (loser->query_temp("marks/fi_m_23")) {
		command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
		loser->delete_temp("marks/fi_m_23");
	}
}


void lose_enemy(object winner)
{
	if (winner->query_temp("marks/fi_m_23")) {
		command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
		winner->set_temp("won_master_kong",1);
		winner->delete_temp("marks/fi_m_23");
	}
}

int got_me()
{
	command("sigh");
	command("say ����ǰ���²���Ҳ�գ�\n");
	return 1;
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="shaolin") return 0;
	message_vision(CYN"$N���Ƶ���������Ե���α��������Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
	return 1;
}
