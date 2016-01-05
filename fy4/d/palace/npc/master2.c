#include <ansi.h>
#include <combat.h>

inherit NPC;
inherit F_MASTER;

int testing(object me);
void check_answer(object me);
void check_accept(object me);

void create()
{
    	set_name("���촸", ({ "master lan", "lan","master" }) );
    	set("gender", "����" );
    	set("nickname",HIB "��������" NOR);
    
    	set("reward_npc", 1);
    	set("difficulty", 2);
    
    	set("age", 45);

    	set("class","yinshi");
    	set("skill_public",1);
    
    	set("combat_exp", 2000000);
    	set("score", 90000);
    	
    	set("apprentice_available", 50);
/*    	create_family("�촸ɽׯ", 1, "ׯ��");
    	set("rank_nogen",1);
    	set("ranks",({"����","С��","����","����","����","����","��ʥ","����"})); */
    	
    	create_family("������", 1, "����");
    	set("rank_nogen",1);
    	set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        CYN"����"NOR,CYN"��ʿ"NOR,HIC"����"NOR }));;
		set("title", "�촸ɽׯ��ׯ��");
    
    	set("long", "
���촸��һ�����õĳ����뻯��ÿ�궼�͵�������������ս������ʤ�����֡� 
���촸��Ƣ�������һ𣬾�����Ե�޹ʵĽ����Ӵ�����˻����ǽ�š�\n");  	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"���촸Ц�����������϶����ֺ�������ʤ����\n",
         }) );
        	
    	set_skill("unarmed", 160);
    	set_skill("hammer", 200);
    	set_skill("force", 160);
    	set_skill("parry", 160);
        set_skill("dodge", 160);
		set_skill("pangu-hammer", 150);
    	set_skill("flying-dragon", 200);
    	set_skill("zuixian-steps", 200);
    	set_skill("magic",150);
    	set_skill("iceheart", 150);
    	set_skill("qiankunwuxing",200);
    	set_skill("move",200);
    
    	map_skill("unarmed", "flying-dragon");
    	map_skill("hammer", "pangu-hammer");
    	map_skill("force", "iceheart");
    	map_skill("parry", "pangu-hammer");
    	map_skill("dodge", "zuixian-steps");
    	map_skill("magic","qiankunwuxing");
    
    
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "hammer.kaitianpidi" :),
		}) );

    	setup();
    	carry_object(__DIR__"obj/bluecloth")->wear();
    	carry_object(__DIR__"obj/jumbohammer")->wield();
}


void init()
{
	add_action("do_challenge","challenge");
	add_action("do_challenge","tiaozhan");
	add_action("do_answer","answer");
	::init();
}

int prevent_learn(object me, string skill)
{
  	if (skill != "magic" && skill!="qiankunwuxing")
  	{
      		command("shake");
      		command("say ��ֻ�������϶�ָ���㼸�ְ��ˣ���û�����㵱ͽ�ܡ�");
      		return 1;
  	}
  	return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "magic" || skill == "qiankunwuxing")
		return 0;
	
	return 1;
}

void attempt_apprentice(object ob)
{

	if (ob->query("class")=="yinshi")
	{
	 	if (REWARD_D->riddle_check(ob,"�촸֮ս"))
	 	{
	 		command("say Ҫ��ʹ򣬴򲻹��͹�������ʲô��");
	 		return;
	 	}
		if (REWARD_D->check_m_success(ob,"�촸֮ս"))
		{
			command("say ��ͽ�������Ѿ�֤�����Լ��ˡ�");
			return;
		}
		call_out("do_recruit",2,ob);
	}
	else
		message_vision(WHT"$Nҡ��ҡͷ��˵��������û����˼��ͽ�ء���\n"NOR,this_object());
   
}


void do_recruit(object ob)
{
	 if (ob && present(ob,environment()))
	 {
	 	message_vision(WHT"$N�������¿��˿�$n����Ȼ������Ц���������㲻�����϶���ͽ���� 
��ô����ʦ���ĵ����㿴���������𣿡�(answer no/yes) \n"NOR,this_object(),ob);
			//add_action("do_answer","answer");
		ob->set_temp("answering_lan",1);
		call_out("check_answer",40,ob);
	 }
}

void check_answer(object me)
{
	if (me)
	{
		me->delete_temp("answering_lan");
		if (present(me,environment()))
		{
			message_vision("$N��$n���ͷ����������ɷ���һ˵һ���ж�˵��������������ʲô����\n",this_object(),me);
			message_vision("$NŤ��ͷ������$n��\n",this_object(),me);
		}

	}
}

int do_answer(string arg)
{
	object me;
	me=this_player();
	
	if(!me->query_temp("answering_lan"))
		return 0;
	if (arg !="yes" && arg !="no")
	{
		return notify_fail("��ֻ�ɴ�yes/no");
	}

	remove_call_out("check_answer");
	me->delete_temp("answering_lan");
	if (arg == "yes")
	{
		message_vision(WHT"$NЦ�ø������ˣ�������Ͱ���Ϊʦ�ɣ��ټ������϶����ҵúú���������
��ͽ�ܶ�£��ס�ˣ��� \n"NOR,this_object());
	}
	if (arg == "no")
	{
		message_vision( WHT"$N˫Ŀ��������$n�������϶���ͽ��Ҳ����ݹ������š����� 
�����Լս(challenge)��ʦ�����Ҿͽ������֣���(accept yes/no) \n"NOR,this_object(),me );
		add_action("do_accept","accept");
		me->set_temp("accepting_lan",1);
		call_out("check_accept",40,me);
	}
	return 1;
}

void check_accept(object me)
{
	if (me)
	{
		delete_temp("accepting_lan");
		if (present(me,environment()))
		{
			message_vision("$N��$n�ӻ��֣���������Ը������ˡ���\n",this_object(),me);
		}
	}
}

int do_accept(string arg)
{
	object me;
	me = this_player();
	if(!me->query_temp("accepting_lan"))
		return 0;
	if (arg !="yes" && arg !="no")
	{
		return notify_fail("��ֻ�ɽ���yes/no");
	}
	remove_call_out("check_accept");
	me->delete_temp("accepting_lan");
	if (arg == "yes")
	{
		message_vision(WHT"$N���ͷ��˵�������ã��Ҿ������������ \n"NOR,this_object());
		REWARD_D->riddle_set(me,"�촸֮ս", 1);		
	}
	if (arg == "no")
	{
		message_vision(HIW"$N��ɫ��������Ϊʦ֮��������������ɽҰ����ս�������������ܴ�Ӧ����\n"NOR,me);
	}
	return 1;
}


int recognize_apprentice(object ob)
{
    if( (string) ob->query("class") == "yinshi" 
    	&& REWARD_D->check_m_success( ob,"�촸֮ս"))	
   // 	&& ob->query("marks/master_lan"))
	        return 1;
	return 0;
}

int do_challenge(string arg)
{
	object me;
	me = this_player();

	if (arg != "master" && arg != "master lan" && arg != "���촸" && arg != "lan")
	{
		return 0;
	}
	
	if (REWARD_D->check_m_success(me,"�촸֮ս"))
	{
		command("say ��ͽ�������Ѿ�֤�����Լ��ˡ�");
		return 1;
	}
	
	if ( REWARD_D->riddle_check( me,"�촸֮ս") != 2
		|| (string) me->query("class") != "yinshi")
	{
		message_vision(WHT"$N��мһ�˶�$n˵����������ʲô������Ҫ�Ϸ���֣��� \n"NOR,this_object(),me);
		return 1;
	}
	
	message_vision(HIG"$n��$N��������"+RANK_D->query_self(me) + me->name() + "Ը��ʦ��ս��\n"NOR,this_object(),me);
	
	
	if((int)me->query("marks/failed_lan") + 10800 > time())
    	{
        	command("say �㲻��ǰ������ң��������ٱȰɣ�");
        	return 1;
    	}
	
	if (this_object()->is_fighting() || this_object()->is_busy())
		command("say ��������æ���Ȼ�ɡ�����");
		
	if (!me->query_temp("marks/fight_lan"))
	{
		message_vision(HIW"$N����Ķ�$n˵��������ô���㡣����Ҳ�ã����аɣ��� \n"NOR,this_object(),me);
	}else
	{
		message_vision(HIW"$N��$n���һ�������ã��е����� \n"NOR,this_object(),me);
	}
	testing(me);	
	return 1;	
}


int testing(object me)
{
 	object weapon,skl;
    	if (this_object()->is_fighting() || this_object()->is_busy())
		command("say ��������æ���Ȼ�ɡ�����");

    me->set_temp("marks/fight_lan",1);
	delete_temp("last_damage_from");
    full_me();
	weapon =me->query_temp("weapon");  

	COMBAT_D->do_attack(me,this_object(),TYPE_PERFORM);
	say(HIR"\n��������˵������һ�У�������\n"NOR);
    if(query_temp("last_damage_from") == me)
    {
		if(!weapon 
			||weapon->query("skill_type")!="whip"
			||me->query_skill_mapped("whip")!="thunderwhip")
		{
			say("\n���������૵�����ԭ�������ϻ�����ô�������书�������� \n");
			say("\n���������Ļ������̾�˿����� \n");
		}else
		{
			command("say �����ƹ�Ȼ�����鴫�������ҵ��书ȴǡǡ�ܿ���������ѧ�Ļ����Ҿͽ��㡣");
	        me->delete("marks/failed_lan");
			REWARD_D->riddle_done( me,"�촸֮ս",50,1);	
		}
		return 1;
    }
	
    	
    COMBAT_D->do_attack(me,this_object(),TYPE_PERFORM);
	say(HIR"\n��������˵�����ڶ��У�������\n"NOR);
	if(query_temp("last_damage_from") == me)
	{
		if(!weapon ||weapon->query("skill_type")!="whip"||
			me->query_skill_mapped("whip")!="thunderwhip")
		{
			say("\n���������૵�����ԭ�������ϻ�����ô�������书�������� \n");
			say("\n���������Ļ������̾�˿����� \n");
		}else
		{
			command("say �����ƹ�Ȼ�����鴫�������ҵ��书ȴǡǡ�ܿ���������ѧ�Ļ����Ҿͽ��㡣");
	        me->delete("marks/failed_lan");
	        REWARD_D->riddle_done( me,"�촸֮ս",50,1);
			
		}
		return 1;
	}


    COMBAT_D->do_attack(me,this_object(),TYPE_PERFORM);
	say(HIR"\n��������˵���������У�������\n"NOR);
	if(query_temp("last_damage_from") == me)
	{
		if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
		{
			say("\n���������૵�����ԭ�������ϻ�����ô�������书�������� \n");
			say("\n���������Ļ������̾�˿����� \n");
		}else
		{
			command("say �����ƹ�Ȼ�����鴫�������ҵ��书ȴǡǡ�ܿ���������ѧ�Ļ����Ҿͽ��㡣");
	        me->delete("marks/failed_lan");
	        REWARD_D->riddle_done( me,"�촸֮ս",50,1);
			
		}
		return 1;
	}
	
	me->set("marks/failed_lan",time());
	if(!weapon ||weapon->query("skill_type")!="whip"
		||me->query_skill_mapped("whip")!="thunderwhip")
	{
		say("\n��������ҡ��ҡͷ��˵������������ֻ�������ƿ��Ժ��ҵĴ������⡣�� \n");			
	}else
	{
		command("shake");
		command("say ����书̫���Ҫ�����ֿ���ˡ��������������ɡ�");
	}
	return 1;
}


