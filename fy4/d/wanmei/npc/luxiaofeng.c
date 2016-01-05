inherit NPC;
void create()
{
        set_name("½С��", ({ "lu", "lu xiaofeng" }) );
        set("gender", "����");
        set("age", 34);
	set("title","������Ϭһ��ͨ");
        set("long","
�������������ϣ����������糾֮ɫ����һ˫����ȴ���������ģ�
üëҲ������ڣ�����üë��½С�\n"); 

        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        
        set("no_arrest",1);
        set("reward_npc", 1);
		set("difficulty", 5);
		
	      
		set("skill_public",1);

        set_skill("force", 150);
        set_skill("unarmed", 150);
		set_skill("parry",150);
		set_skill("lingxi-zhi",150);
		set_skill("stormdance",150);
		set_skill("dodge",150);
	
		map_skill("unarmed","lingxi-zhi");
		map_skill("parry", "lingxi-zhi");
		map_skill("dodge", "stormdance");
	
		set_temp("xinyoulingxi", 1);
		
        setup();
		carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	
	if (interactive(this_player()) && environment())
	if (environment()->query("lu_cave"))
	    {
	    	REWARD_D->riddle_done(this_player(),"����֮��",10,1);
	    	if (QUESTS_D->verify_quest(this_player(),"��½С��"))
				QUESTS_D->special_reward(this_player(),"��½С��");
		}
	
	if (REWARD_D->check_m_success(this_player(), "ԡѪ����")
		&& !this_player()->query("free_learn/lingxi-zhi")){
		command("say ��л���ӥ�����ߡ�");
		command ("say ����Ϊ�����粻����������Щ����ɡ�");
		message_vision("$N���˿��������ֻ���ҵ��书�Ǽ��к��ļ��츳�߲������ɡ���\n",this_object());
		command ("say �㻹�Ǻú���һ��ɣ�����ǿ����ʦ���кܶࡣ\n");
		this_player()->set("free_learn/lingxi-zhi",1);
	}						
}

int recognize_apprentice(object ob){
	if ( this_player()->query("free_learn/lingxi-zhi")) {
			return 1;
		}	
	return 0;
}

int prevent_learn(object me, string skill)
{
  	if (skill != "lingxi-zhi" && skill != "unarmed")
  	{
      		command("shake");
      		command("say �ҿ�ֻ��Ӧ������Ϭָ����");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/lingxi-zhi") 
		&& (skill == "lingxi-zhi" || skill == "unarmed"))
		return 0;
	
	return 1;
}