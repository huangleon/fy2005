inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void smart_fight();

int your_score = 0;
void create()
{
    	set_name("���Ŵ�ѩ", ({ "master ximen", "ximen", "master" }) );
    	set("title", "��÷ׯ��");
    	set("gender", "����");
     	set("nickname", RED "����" NOR );
    	set("age", 34);
    	set("reward_npc", 1);
    	set("difficulty", 30);
    	set("class","fighter");
    	set("long","���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˡ��޽����ľ��硣\n"); 
    
    	set("attitude", "peaceful");
    	set("combat_exp", 20000000);
    	
    	set("score_cost",20000);
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
        
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"���Ŵ�ѩŭ�����½С�������ӵ�����ɽׯ����ҲҪɱ���㣡��\n",
        }) );

    	set("inquiry", ([
        	"��ʦ": "�������и���أ����������Ϊʦ�ģ��ý������в�����
��������(accept test)��\n",
        	"apprentice": "�������и���أ����������Ϊʦ�ģ��ý������в�����
��������(accept test)��\n"

        ]) );

    	create_family("��÷ɽׯ", 1, "ׯ��");
    	set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�", "�ܹ�","���ܹ�","��ׯ��" }));
    	set("rank_nogen",1);

    	set_skill("force", 180);
    	set_skill("unarmed", 160);
    	set_skill("sword", 200);
    	set_skill("parry", 160);
    	set_skill("dodge", 160);
    	set_skill("move", 160);
    	set_skill("doomforce", 150);
    	set_skill("doomstrike",200);
    	set_skill("doomsteps", 200);
    	set_skill("doomsword",150);
    	set_skill("perception",150);

    	map_skill("force", "doomforce");
    	map_skill("unarmed", "doomstrike");
    	map_skill("sword", "doomsword");
    	map_skill("dodge", "doomsteps");
    	map_skill("move", "doomsteps");
    	map_skill("parry","doomsword");


    	setup();

    	carry_object(__DIR__"obj/xuejian")->wield();
    	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
    	::init();
    	add_action("do_accept", "accept");
}

int do_accept(string arg)
{
    	mapping guild;
    	int extra;	
    	int mgin,mkee,msen;
    
    	if( arg== "test" )    {
		if(this_player()->query("family/master_id") == this_object()->query("id")){
            		say("\n���Ŵ�ѩ�������ͷ�������Ѿ�֤������һ������֮���ˣ�\n");
            		return 1;
		}
		if (this_object()->is_busy()) {
			tell_object(this_player(),"���Ŵ�ѩ��æ���أ�û�����㡣\n");
			return 1;
		}
			
		if (this_object()->is_fighting()) {
			command("say ��������ʰ��������ְ��ŵļһ");
			return 1;
		}
		mgin=(int)query("max_gin");
	    	mkee=(int)query("max_kee");
	    	msen=(int)query("max_sen");
	    	set("eff_kee",mkee);
	    	set("eff_gin",mgin);
	    	set("eff_sen",msen);
	    	set("gin",mgin);
	    	set("kee",mkee);
	    	set("sen",msen);
		extra=100;
		
        	say("\n���Ŵ�ѩ���˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
        	this_object()->add_temp("apply/attack", extra*5);	
		this_object()->add_temp("apply/damage",extra*2);
        	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
        	this_object()->add_temp("apply/attack", -extra*5);	
		this_object()->add_temp("apply/damage",-extra*2);                    
               	if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) {
                        say("���Ŵ�ѩ̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
            		return 1;
        	}
        	
        	say("\n���Ŵ�ѩ˵�������ǵڶ���....\n\n");
        	this_object()->add_temp("apply/attack", extra*5);	
		this_object()->add_temp("apply/damage",extra*4);
        	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
        	this_object()->add_temp("apply/attack", -extra*5);	
		this_object()->add_temp("apply/damage",-extra*4);                      
        	if( (int)this_player()->query("kee") < 0  || !present(this_player(), environment())) {
                        say("���Ŵ�ѩ���ߡ���һ����˵��������������಻�����ļһ�....\n");
            		return 1;
        	}
        	
        	say("\n���Ŵ�ѩ˵��������������....\n\n");
        	this_object()->add_temp("apply/attack", extra*5);	
		this_object()->add_temp("apply/damage",extra*4);
        	COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
        	this_object()->add_temp("apply/attack", -extra*5);	
		this_object()->add_temp("apply/damage",-extra*4);                      
        	if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) {
                        say("���Ŵ�ѩ̾������ϧ���ѵ���һ���书���޴���....\n");
            		return 1;
        	}
        		        
        	say("\n���Ŵ�ѩ������Ц��˵������������ٵ�һ������֮�ţ�\n\n");
        	say("\n�������ּ�į�������Ҳ������κ��ˡ�������\n");
        //	your_score = this_player()->query("score");
        //	command("recruit " + this_player()->query("id") );
        	return 1;
    }
    return 0;
}
/*
void recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
    	ob->add("betrayer",-1);
    	if(ob->query("betrayer") < 0) ob->set("betrayer",0);
}*/

void killed_enemy(object who)
{
    	command("say ����֮ͽ��������ϧ��\n");
}

void die()
{
    	object killer;
    	if(objectp(killer = query_temp("last_damage_from"))){
    		if (killer->query("marks/won_lu")) killer->set("marks/kill_ximen", 1);
    	}
    	::die();
}

smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2 && enemy[1]->is_zombie()&& random(3)>0) {
		who->perform_action("sword.zombie-wp1");
		return;
	}
	if (!random(5))
		who->perform_action("sword.hunranyijian"); 
	return;
}  

