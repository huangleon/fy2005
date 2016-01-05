inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int kill_him();
int jian();

void create()
{
    	set_name("Բ��", ({ "master yuan", "master"}) );
    	set("nickname", HIG "ãΪ" NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "����" );
    	set("reward_npc", 1);
    	set("difficulty", 1);
    	
    	set("class","shaolin");
    
    	set("age", 64);
    	
    	set("attitude","friendly");
        set("long","���ֵڶ�ʮ������ʦ������ר�Ŵ��������׼ҵ����书��\n��Ҫ"YEL"������"NOR"���ȵ���ͬ����С�");
    	set("guard_msg","$N��$n�ȵ��������ӷ�,�����徲֮��,�������ɱ��?ʩ����ˡ���ĵ����ˣ�\n"NOR);
    	create_family("������", 22, "����");
    	    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"ɳ��","ɮ��","�޺�","���","����","��ɮ","��ʦ",
		"����","���ó���","����Ժ����","��������","����Ժ����",
		YEL"����Ժ����"NOR,YEL"������"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		
    	set("combat_exp", 500000);
    
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.qianshouqianbian" :)
    	}) );
    	
    	set_skill("move", 90);
    	set_skill("dodge", 90);
    	set_skill("force", 90);
    	set_skill("literate", 100);
    	set_skill("unarmed",90);
    	set_skill("puti-steps",90);
    	set_skill("dabei-strike",90);
    	set_skill("zen",60);
    	set_skill("chanting",90);
    	set_skill("xiaochengforce",90);
    	set_skill("parry",90);
    	set_skill("foreknowledge",90);
		set_skill("perception",90);
		set_skill("hammer",100);    	
    	set_skill("liuxing-hammer",100);
    	set_skill("lianxin-blade",130);
    	set_skill("blade", 130);
    	set_skill("staff", 100);
    	set_skill("fumostaff",100);
    	    	
    	map_skill("blade", "lianxin-blade");
    	map_skill("staff","fumostaff");
    	map_skill("parry","fumostaff");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "dabei-strike");
    
    	set("inquiry", ([
        	"������": (: jian()  :),
        	"master": (: jian()  :),
        ]) );
    	setup();
    	carry_object(__DIR__"obj/monk22_cloth")->wear();
    	carry_object(__DIR__"obj/staff")->wield();

}

void attempt_apprentice(object me)
{
    	if(me->query_temp("won_master_kong"))
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
              	if (me->query_skill("zen",1) >= 60) {
        			command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
           			me->set_temp("marks/fi_m_22",1);
           			return 1;
        		
        		}
        		command("say ͽ�������������Ϊ̫ǳ��������ɲ��а���\n");	
        		tell_object(me,"����60��������\n");	// 148k
        			
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
    	if (loser->query_temp("marks/fi_m_22")) {
    		command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
    		loser->delete_temp("marks/fi_m_22");
    	}
}

void lose_enemy(object winner)
{
    	if (winner->query_temp("marks/fi_m_22")) {
    		command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
    		winner->set_temp("won_master_yuan",1);
    		winner->delete_temp("marks/fi_m_22");
    	}
}

void init() {
    	::init();
	add_action("do_killing", "kill");
    	add_action("do_answer","answer");
}


int jian() {
	object me;
	me=this_player();
	command("say �������....��....����ʲô���𣿣�answer��");
	me->set_temp("shaolin/ask_yuan",1);
	return 1;
}

int do_answer(string arg)
{
	object me = this_player();
	if (!this_player()->query_temp("shaolin/ask_yuan"))
	{
		command("say "+arg+"��ʩ�����ڸ�ƶɮ˵��ô��");
		return 1;
	}
	if (!REWARD_D->riddle_check(me,"����֮��") && !REWARD_D->check_m_success(me,"����֮��")) 
	{
		command("say "+arg+"��ʩ�����ڸ�ƶɮ˵��ô��");
		return 1;
	}
	if(arg == "��Ҫ��" || arg =="emergency")
	{
		command("consider");
		command("say ʲô��Ҫ�£�ɽ�µ����ʩ�����������������ɣ�");
		return 1;
	}
	if(arg == "���鱻��")
	{
		command("say �ã�������Ժ�򱱣���ȥ�ɣ�");
		this_player()->delete_temp("shaolin/ask_yuan");        	
		this_player()->set_temp("see_fangzhang",1);
		return 1;
	}
	command("dunno");
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


