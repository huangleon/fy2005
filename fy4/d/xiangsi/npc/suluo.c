// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>

void smart_fight();
int leave();
int look_stone();

void create()
{
        set_name("Ѧ����", ({ "xue suluo", "xue", "suluo", "master" }) );

		set("class","moon");

		create_family("��¹�", 3, "");
		set("nickname",HIC"ҹ�����ضϳ���"NOR);
		set("title","����칬");

        set("gender", "Ů��");
        set("apprentice_available", 1);

		set("guard_msg",CYN"$N��ü�����۸�����¹����ˣ��۸������������ˣ�\n"NOR);

        set("reward_npc", 1);
		set("difficulty", 4);
		set("per", 32);
		set("age",20);
		set("attitude","peaceful");

        set("combat_exp", 3000000);
        
		set("long","Ѧ������������ױ���ߣ���ü��չ��\n");
		set("chat_chance", 1);
		set("chat_msg", ({
			"Ѧ��������̾Ϣ����֪���ؽ����������Ե�֣��������������˶ϣ�����\n",
			"Ѧ����˵���������뵽ô�����������ǻ�ɽһ������ɽ�ŵ�ʯ�������ؽ���������ġ�\n",
		}) );

		set("inquiry",([
		"����": (: look_stone :),
		"�": (: look_stone :),
        "leave": (: leave :),
        "�ؽ��": (: look_stone :),		
    	]) );

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

        set("rank_nogen",1); 
//		set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,RED"��˧"NOR,HIR"��ɽ��"NOR }));
        
        set_skill("force", 160);    
		set_skill("dodge", 200);    
		set_skill("move", 150);    
		set_skill("parry", 150);    
		set_skill("literate", 100);
		set_skill("blade", 200);    
		set_skill("chanting",150);
		set_skill("snowforce",170);
		set_skill("chillblade",190);
		set_skill("stormdance",150);
		set_skill("perception",150);
		set_skill("foreknowledge",100);
		set_skill("spells",100);
		
	    map_skill("force","snowforce");
	    map_skill("blade","chillblade");
	    map_skill("parry","chillblade");
	    map_skill("move","stormdance");
	    map_skill("dodge","stormdance");
     	setup();

		carry_object(__DIR__"obj/xueyu")->wear();
		carry_object(__DIR__"obj/xianyue")->wield();

}

void reset()
{
	set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("bored");
                command("shake");
                command("lazy xue suluo");
        }
}


void do_recruit(object me)
{
	if( (string)me->query("class") != "moon" )
	{
		command("loveme " + me->query("id") );
	}
	else
	{
		command("woman");
		command("say "+me->name()+"����һ��Ҫ�����һ��������ȥ����");
		// ң�뵱�꣬ѩ����������˵�����պ���д�ɣ�������
		command("recruit " + me->query("id") );
	}
}
		
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "moon");
	add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
//	add_action("do_accept", "accept");
        if( !query_heart_beat(this_object()) ) {
		set_heart_beat(1); 
	}
}

int do_accept(string arg)
{
	object me = this_player();
	if (me->query("family/master_name") == "Ѧ����" && me->query("family/master_id") == "xue suluo" && me->query("class") == "moon" && !me->query("annie/moon_master"))
	{
		if (arg == "yes")
		{
			ccommand("consider");
			ccommand("look "+me->query("id"));
			if (me->query("combat_exp") < 1280000)	// ��1.28M�������Ϳ���ȥleh
			{
				ccommand("say �����������µķɵ����ˣ�Ҫ��ʤ�����㻹������ϰ��");
				ccommand("pat "+me->query("id"));
				return 1;
			}
			else
			{
				ccommand("shu "+me->query("id"));
				ccommand("consider");
				ccommand("ok");
				ccommand("say ����ؽ��ȥ�����������Ϳ����˽���׮�¹ʣ���");
				ccommand("say ����Ե�ɽ��ȥ�ҹ�����ʤ����������һ��֪��������");
				ccommand("pat "+me->query("id"));
				ccommand("sweat "+me->query("id"));
				me->set("annie/moon_master",1);
				return 1;
			}
		}
		else if (arg == "no")
		{
			ccommand("sigh");
			ccommand("say ��Ҫ��ô��źã�������");
			return 1;
		}
	}

	return 0;
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}

int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object target;
	int i;
	target = select_opponent();
	
	i = query("combat_exp") * 100 / target->query("combat_exp") ;

	ccommand("exert bingpojingbi");
	ccommand("perform dodge.shuangtianxuewu");

	if (!query_temp("weapon"))
		if (ccommand("get newmoon blade"))
			if (ccommand("wield newmoon blade"))
				stop_busy();
	
	if (i > 180 && (userp(target) || query("test")))
		SKILL_D("chillblade")->perform_target(this_object(),"yuhouchuhong",target);
		
	if (query("mana") && (userp(target) || query("test")))
		ccommand("perform qinghui");
}

int leave()
{
    if (this_player()->query("class")!="moon") return 0;
	message_vision(CYN"$N������ɨ��$nһ�ۡ�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵����Ȼ��һ��Ҫ�ߣ���Ҳ������ǿ��\n"NOR,this_object(),this_player());
	message_vision(CYN"$N˵��ֻ�����и��յľ��裬���Ƕ��޷����õ��ˡ�\n"NOR,this_object(),this_player());
    return 1;
}

int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();
	if (REWARD_D->riddle_check(me,"������Թ") != 4 && REWARD_D->riddle_check(me,"������Թ") !=5 )
	{
		ccommand("say �������˵��İ�ϻ������ɻ������ӡ���");
		return 1;
	}

	if (REWARD_D->riddle_check(me,"������Թ") == 4 )
	{
		ccommand("say �⡭��");
		ccommand("emote ��ü��˼Ƭ�̣��ƺ��������ã�����");
			REWARD_D->riddle_set(me,"������Թ",5);
		return 1;
	}

	message_vision("$N˵�����ؽ�����һս֮���ѽ���Ω��֮�ƣ�ֻ�����跨�ҵ����˽�µ��⡣\n"NOR,this_object(),this_player());
	message_vision("$N˵������˵ɽ�µĹ���̫�������������һս��������֪���ס�����\n"NOR,this_object(),this_player());
			REWARD_D->riddle_set(me,"������Թ",6);
    return 1;
}

/*
Ѧ����Ŀǰ��ѧ��ʮ�ּ��ܣ�

  �������� (blade)                         - �����뻯 150/    0
�������߾� (chillblade)                    - �����뻯 150/    0
  ��Ծ����֮�� (dodge)                     - �Ƿ��켫 160/    0
  �ڹ��ķ� (force)                         - һ����ʦ 180/    0
  ����ʶ�� (literate)                      - ��Ȼ��� 135/    0
  �����Ṧ (move)                          - һ����ʦ 180/    0
  ����ж��֮�� (parry)                     - �Ƿ��켫 160/    0
  �������֮�� (perception)                - ������� 100/    0
����ѩ�ľ� (snowforce)                     - �����뻯 140/    0
��������� (stormdance)                    - �Ƿ��켫 160/    0
*/

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
