// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
string quest();

#include <ansi.h>
void create()
{
    	set_name("�Ϲٽ��", ({ "master shangguan", "master", "shangguan" }) );
    	set("nickname", RED"����˫��"NOR);
    	set("gender", "����" );
    	set("class", "assassin");
    
    	set("long","
һ������վ������ǰ�����ţ���ʱ������ھ����Ϲ��������ģ�����ż����¶��
һ˿�����Ц�ݡ�����վ�ŵġ�����Ϊһ����ֻҪ���������ͻ����Լ��ľ�����
�ڣ�һ���˵ľ������ɳڣ���������ɴ���\n");
    	create_family("��Ǯ��", 1, "����");
       	set("rank_nogen",0); 
	set("guard_msg",HIW"$N�ȵ���������ǰɱ�ҽ�Ǯ��ĵ��ӣ�������ˣ�\n"NOR);
    	set("combat_exp", 25000000);
    	set("score", 200+random(200000));
    
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "hammer.longfengshuangfei" :),
        }) );
    	set("age", 44);
    	set("per", 30);
    	
    	 set("inquiry", ([
	       	"��ļ": 	(: quest :),
	       	"����": 	(: quest :),
	       	"zhaoren": (: quest :),
	       	"job": (: quest :),
         ]) );
    	
    	set("reward_npc", 1);
    	set("difficulty", 40);
    	set("attitude","friendly");

	set_temp("apply/haste",300);
	    	
    	set_skill("move", 200);
    	set_skill("parry", 240);
    	set_skill("dodge", 240);
    	set_skill("force", 200);
    	set_skill("jingxing",150);
    	set_skill("hammer", 300);
    	set_skill("flame-strike",200);
    	set_skill("unarmed",230);
    	set_skill("jinhong-steps",200);
    	set_skill("longfenghuan",200);
    	    	
    	map_skill("dodge", "jinhong-steps");
    	map_skill("hammer", "longfenghuan");
    	map_skill("parry", "longfenghuan");
    	map_skill("force", "jingxing");
    	map_skill("unarmed", "flame-strike");
    	map_skill("move","jinhong-steps");

	set_temp("apply/attack",100);
	
	setup();
	carry_object(__DIR__"obj/yellow_suit")->wear();
    	carry_object(__DIR__"obj/hat")->wear();
    	carry_object(__DIR__"obj/longfenghuan")->wield();
}


void attempt_apprentice(object me)
{
	 message_vision(CYN"$N������˵������������ͽ��������������������ȥ��\n"NOR, this_object(), me);
}


void smart_fight(){
	if (this_object()->query("kee") < this_object()->query("max_kee")/2) {
		this_object()->ccommand("exert riposte");
		this_object()->ccommand("haha");
	}
			
	if (this_object()->query_temp("weapon"))
	if (random(2))
		this_object()->ccommand("perform longfengshuangfei");
}
		
string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object me = this_player();
	
	if (me->query("quest/short") == "ȥ�Ϲٽ�������ļ���¶�")
	{
		if (me->query("quest/duration") == 441)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","ɱ���޺�");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"�������޺���ɱXXX"+WHT"�����޺�"NOR);
				me->set("annie_quest/target","���޺�");
				
				me->set("quest/short", WHT"�������޺���ɱ"+ n + WHT"�����޺�"NOR);
				me->set("quest/location", "�����޺���");
				me->set("quest/difficulty",n*30);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*60);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "���ֲ������ճɴ󻼣�����ȥ���ֺ����޺���ɱ�������޺���\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}

		
		if (me->query("quest/duration") == 442)	// ��С��
		{
				n=1+random(3);
				me->set("annie_quest/name","ɱͭ�޺�");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"�������޺���ɱXXX"+WHT"��ͭ�޺�"NOR);
				me->set("annie_quest/target","ͭ�޺�");
				
				me->set("quest/short", WHT"�������޺���ɱ"+ n + WHT"��ͭ�޺�"NOR);
				me->set("quest/location", "�����޺���");
				me->set("quest/difficulty",n*30);	// ÿ��һ���Ͷ�30% reward
				me->set("quest/duration",900+n*60);	// ÿ��һ���Ͷࣱ����
				me->set("quest_time",time());
				arg= "���ֲ������ճɴ󻼣�����ȥ���ֺ����޺���ɱ����ͭ�޺���\n";
				tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);
				return arg;
		}
		
		return "�������ûʲô���飬�㲻��û�����ʦ���ݲ�ɡ�\n";	// error mark.
	}
	else
		return "action�Ϲٽ��һ�ﲻ����";
	
	return " ";
}
