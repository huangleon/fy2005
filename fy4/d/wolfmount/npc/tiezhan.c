inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();
void create()
{
	set_name("��ս", ({ "master tiezhan", "master"}) );
    	set("nickname", HIY "ս�ǵ�"NOR);
	set("gender", "����" );
	set("age", 34);

	set("reward_npc", 1);
	set("difficulty", 2);
	set("attitude","friendly");
	set("combat_exp", 400000);

	set("long","һ�������½󣬺�����Ĵ󺺣�����һ���;��ô��˹�������\n");

	create_family("��ɽ", 4, "��ͷ��");
       	set("rank_nogen",1); 
    set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
	set("ranks",({ "С���","�����","���ǵ�","ҹ�ǵ�","ս�ǵ�",
				"СͷĿ","��ͷĿ","Сͷ��","��ͷ��","���","����",
				"����",RED"��ʥ"NOR,RED"��˧"NOR,RED"����"NOR,HIR"����֮��"NOR}));
    	    	
  	set("class","wolfmount");
  
	set("guard_msg",HIW"$N��$n�ȵ�����ɽ�ӵ�,ͬ����֦,�����������꣡\n"NOR);
  
      	set("inquiry", ([
           	"leave" : (: leave :),
        ]) );
        
    	set_skill("hammer", 120);		// these two skills are hidden
    	set_skill("assassin-hammer",100);
    	
    	set_skill("literate", 100);
    	set_skill("move", 120);
		set_skill("dodge", 120);
    	set_skill("force", 140);
    	set_skill("parry", 120);
		set_skill("unarmed",120);
    	set_skill("summonwolf",150);
    	set_skill("wolf-strike",150);
    	set_skill("wolf-force",120);
    	set_skill("xueyeqianzong",120);
    	set_skill("perception", 100);
    	set_skill("foreknowledge",100);
    	set_skill("chanting",100);
    
    	map_skill("dodge", "xueyeqianzong");
    	map_skill("unarmed", "wolf-strike");
    	map_skill("hammer", "assassin-hammer");
    	map_skill("parry", "assassin-hammer");
    	map_skill("force", "wolf-force");
    	
    	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.duanhou" :),
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/pifeng")->wear();
    	carry_object(__DIR__"obj/stonehammer")->wield();  
}

void attempt_apprentice(object me)
{
      	if( (int)me->query_cps() >=10 )
    	{
    		command("say ����ɽ�ֶ���һ����η�޾����Ѫ���ɣ���ϲ�ɺذ���\n");
        	command("recruit " + me->query("id") );
        	return;
    	}
    	else
    	{
		command("shake");
        	command("say �ҿ������²������ţ���ô�ܼ�Ԧ����Ⱥ�ǣ��㻹���߰ɣ�\n");
    	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
}

int accept_fight(object me)
{
        if(me->query("class") == "wolfmount")
        {
            	if (me->query_skill("summonwolf",1) < 150)
            	{
            		command("say ��Ļ�����̫��ˣ�����ʲô������150����\n");
            		return 0;
            	}
            	command("say �ã�Ӯ���ң���Ϳ���ȥ����ɽ�и������ʦ���ˣ�\n");
        	return 1;
        }
        else
        {
        	command("say ��ʲô��Ц�����Ӵ�������ܣ�Ҫ���־�����ģ�\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
    	command("say ���������Ͱ����������˵������ʦ�������ˣ����ˣ�\n");
}

void lose_enemy(object winner)
{
    	command("say ��ͽ������������ǰ;����ɽ����ʦүʦ��ѧȥ�ɡ�\n");
	winner->set_temp("marks/wolf_win_tiezhan",1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}


int leave() {
	if (this_player()->query("class")!="wolfmount") return 0;
	message_vision(CYN"$N��м�ؿ�����һ�ۡ�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵�����߿��ԣ��Ժ��ָ������ɽ�Ķ����ؼ���\n"NOR,this_object(),this_player());
	return 1;
}


int prevent_learn(object me, string skill)
{
  	if (skill == "hammer" || skill == "assassin-hammer")
  	{
      		return 1;
  	}
  	return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "hammer" || skill == "assassin-hammer")
		return 1;
	
	return 0;
}