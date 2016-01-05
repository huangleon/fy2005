#include <ansi.h>
inherit F_MASTER;
inherit SMART_NPC;
int leave();

void create()
{
	set_name("������", ({ "dugu shang","dugu" }) );
	set("gender", "����" );
	set("long","
һ����Ͱ��ݹ���᾵������ˣ�һ�������͵�Ƥ��������Ƥ��������ϣ�
������Ҳ���������ߣ�ÿһ�֣�ÿһ�綼Ǳ���Ų��ɲ��������գ����ǿ�
����������ʹ֮��ʹ����������µ�һ���֡�\n"
	);
        create_family("�����", 2, "��ʹ");
        set("attitude", "peaceful");
        set("rank_nogen",1);
        set("class","knight");
        
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
    	set("ranks",({"�̾�ͯ","Ѱ����","���ƿ�","ҩʦ","����ʿ","������",
    			"����ͳ��","����ʹ","��ʹ","ɫʹ","��ʹ","��ʹ",
    			RED"�����ʹ"NOR,RED"�����ʹ"NOR,RED"һ�ֲ�����"NOR,HIR"�����"NOR}));
	
		set("reward_npc", 1);
		set("difficulty", 2);
    	
    	set("perform_busy_d", "knight/dodge/windy-steps/fengliu");
    	set("perform_weapon_attack", "knight/axe/xuanyuan-axe/guifushengong");
    	set("skill_type_w", "axe/xuanyuan-axe");
	
		set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    	
		set("age", 45);
        set("per", 4);
                
        set("combat_exp", 1500000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������һ����ббƳ����һ�ۡ�\n",
        }) );
        
        set("inquiry", ([
    
    	]));
        
        set_skill("foreknowledge",100);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("longlife-force", 150);
        set_skill("axe", 200);
        set_skill("xuanyuan-axe", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("move", 150);
        set_skill("literate",100);
        set_skill("chanting",100);
        set_skill("windy-steps", 150);
        set_skill("hanshan-strike", 140);
        set_skill("perception", 120);
        set_skill("dream-herb",100);
        set_skill("herb",100);
        
        map_skill("herb","dream-herb");
        map_skill("dodge", "windy-steps");
        map_skill("unarmed", "hanshan-strike");
        map_skill("force", "longlife-force");
        map_skill("axe", "xuanyuan-axe");
        map_skill("parry", "xuanyuan-axe");
        
        setup();
  		carry_object("/obj/weapon/axe_l")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
}

void attempt_apprentice(object me)
{
	command("smile");
    command("recruit " + me->query("id") );
	return;
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
    	ob->set("class", "knight");
}

int accept_fight(object me)
{
        object ob;
        ob = this_object();
	
	if (me->query("class")!= "knight" && me->query_temp("marks/knight_win_dugu")) {
		command("say �����Ϸ�����Ƿ�ѣ������ˣ�������ɡ�");
		return 0;
	}
		
	if(me->query("family/family_name") == query("family/family_name") &&
	   	me->query("family/master_id") == query("id"))
        {
        	if (ob->is_busy() || ob->is_fighting()) {
        		command("say ���ţ����Ƚ�����С����˵��");
        		return 0;
        	}
        	if (me->query_skill("windy-steps",1)< 150) {
        		command("say �����̫���ү���˻�˵�ҽ�ͽ�޷������ɡ�");
        		tell_object(me,"����150��������ʮ��ʽ��\n");
        		return 0;
        	}
        		
        	full_me();
        	message_vision(CYN"���������˿���������ǽڿ������졣\n"NOR,ob);
        	command("say �ã���Ӯ���ң���Ϳ���ȥ����үѧϰ�ˣ�\n");
        	me->set_temp("marks/fight_dugu",1);
        	return 1;
        }
        else
        {
        	command("say ��֪С�����ط�����ǰ���󵶣����Ϸ��ѵ��һ��Ҳ�ã�\n");
			me->set_temp("marks/fight_dugu",1);
			return 1;
        }
}

void win_enemy(object loser)
{
    	command("say ��������ӹ�ţ�\n");
}

void lose_enemy(object winner)
{
    	object owner;
    	mapping all;
    	
    	if (objectp(winner))
    	if (objectp(owner = winner->query("possessed")))
    		winner = owner;
    		
    	command("say �������ˡ���\n");
    	if (winner->query_temp("marks/fight_dugu"))
    	{
    		winner->set_temp("marks/knight_win_dugu",1);
    		if (!REWARD_D->check_m_success(winner,"��ɫ����"))
    		{
    			REWARD_D->riddle_set(winner, "��ɫ����/qi", 1);
    			tell_object(winner, WHT"������ˡ���ɫ�������еġ�����\n"NOR);
    		}
    		 		
    		all = winner->query("riddle/��ɫ����");
			if (mapp(all) && sizeof(all) == 4)
				REWARD_D->riddle_done(winner,"��ɫ����",50,1);	
    	}
}

