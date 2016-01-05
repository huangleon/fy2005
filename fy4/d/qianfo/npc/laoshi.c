// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
int give_silk();
inherit NPC;

void smart_fight();

void create()
{
        set_name("��ʵ����", ({ "lao shi", "lao"}) );
        set("gender", "����" );
        set("age", 32);
        set("class", "bonze");
        set("long", "
��ʵ�����������񲣬��������ģ����Ĺ���Ҳ����ˣ�
��ʵ���д�����˵�ѻ������Ե�������ʵ���У�\n");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        
    	set_skill("unarmed", 120);
    	set_skill("dabei-strike",120);
    	set_skill("force", 120);
    	set_skill("dodge", 120);
    	set_skill("literate", 100);
    	set_skill("chanting", 120);
    	set_skill("parry", 120);
    	set_skill("lotusforce", 120);
    	set_skill("buddhism", 100);
    	set_skill("nodust-steps",120);
    	set_skill("staff",120);
    	set_skill("cloudstaff",120);
    	set_skill("perception", 100);
    	set_skill("foreknowledge", 100);
		set_skill("move", 100);
		set_skill("magic", 100);
		set_skill("essencemagic", 100);
				
		map_skill("force", "lotusforce");
    	map_skill("dodge","nodust-steps");
    	map_skill("unarmed","dabei-strike");
    	map_skill("staff","cloudstaff");
    	map_skill("parry","cloudstaff");
    	map_skill("magic","essencemagic");
    	
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
				(: smart_fight() :),
      	}) );
              
        set("chat_chance", 1);
        set("chat_msg", ({
			"��ʵ����̾��������淣�ң�����ȥ����ǧ��¥��\n",
			"��ʵ���д��˴��Լ���ͷ���������˾�����ڿ�\n",
			"��ʵ����������������������ü���������ֵĲ����ָ����ң�\n",
			(: random_move :),
        }) );
        
        set("inquiry", ([
                "�߲�˿�д�" : (: give_silk:),
                "silk" : (: give_silk:)
        ]));
	
		setup();
		carry_object(__DIR__"obj/monk_cloth")->wear();
}

void	smart_fight(){
		
		command("conjure mind_sense");
		return;
}

int give_silk()
{
	if( (int)query("given") >= 7 )
	{
		command("say �����ˣ��������ˣ�����\n");
		return 1;
	}
	command("say ��Ҳ������Բ֮ҹ��ȥ�����Ͻ�֮�۵Ŀ�����ս��\n");
	command("say ���ҵÿ����㣬���㹻������\n");
	if (this_player()->query_temp("marks/laoshi_win")) 
		this_player()->delete_temp("marks/laoshi_win");
	this_player()->set_temp("marks/laoshi",1);
	return 1;
}

void win_enemy(object loser)
{
	command("say ��λ" + RANK_D->query_respect(loser)+ "���㻹������\n");
}

void lose_enemy( object winner)
{
	object silk;
	command("say ��λ" + RANK_D->query_respect(winner)+ "����Ĺ��򲻴�\n");
	if (!winner->query_temp("marks/laoshi_win"))
	{
		silk = new(__DIR__"obj/silk");
		if (!silk->move(winner))
			silk->move(environment());
      	add("given",1);
		winner->set_temp("marks/laoshi_win",1);
		REWARD_D->riddle_done(winner,"�߲ʶд�",10,1);
	}
}


int accept_fight(object me)
{
	if(me->query_temp("marks/laoshi"))
	{
		command("say �ã���Ӯ���ң���˿��������ģ�\n");
		full_me();
		me->delete_temp("marks/laoshi");
        return 1;
	}
	else
	{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
	}
}


void reset()
{
	delete("given");
}
