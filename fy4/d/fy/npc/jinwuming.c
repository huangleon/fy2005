// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int smart_fight();


void create()
{
    	set_name("荆无命", ({ "master jing", "master", "master jingwu" }) );
    	set("nickname", RED"左手剑"NOR);
    	set("long","
这人的身子站得更直，更挺，就像是一杆枪。他整个人似已麻木，既不知痛痒，
也不知哀乐。\n"	);

    	set("gender", "男性" );
    	set("age", 44);

    	set("reward_npc", 1);
    	set("difficulty", 20);
	
	set("fy41/jq_sharenruma",1);
    	set("ssrm_7hit",1);		// ALways 7 hits.
    	set("per", 3);
        
    	set("attitude","friendly");
    	set("toughness", 200);
    	    	
    	set("class","assassin");	
    	create_family("金钱帮", 2, "护法");
    	set("rank_nogen",1); 
	set("ranks",({"帮众","副堂主","堂主","副坛主","坛主",
                      "副舵主","舵主","护法","大护法",
                      "长老",RED"大长老"NOR,RED"副帮主"NOR,RED"帮主"NOR}));
    	set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,10000000,15000000 }));
                             
	set("combat_exp", 5000000);
    	    
    	set_skill("dodge", 200);
    	set_skill("force", 180);
    	set_skill("jingxing",150);
    	set_skill("sword", 300);
    	set_skill("jinhong-steps",200);
    	set_skill("unarmed",200);
    	set_skill("flame-strike",200);
    	set_skill("move",200);
    	set_skill("lefthand-sword",200);
    	set_skill("sharen-sword",180);
    	set_skill("parry",200);
    
    	map_skill("parry","lefthand-sword");
    	map_skill("unarmed","flame-strike");
    	map_skill("dodge", "jinhong-steps");
    	map_skill("sword", "sharen-sword");
    	map_skill("force", "jingxing");
	map_skill("move","jinhong-steps");

	set_temp("apply/attack",100);
	
    	set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        	(: smart_fight():),
    	}) );  

    	setup();
    	  	    	
    	carry_object(__DIR__"obj/yellow_shirt")->wear();
    	carry_object(__DIR__"obj/hat")->wear();
    	carry_object(__DIR__"obj/jin_sword")->wield();
}


void attempt_apprentice(object me)
{
      	message_vision(CYN"$N冷冷地看了$n一眼，一语不发。\n"NOR, this_object(), me);
      	return;	
}


int smart_fight()
{
	int i;
	object me, *enemy;
	
	me = this_object();
	enemy = me->query_enemy();
	i = sizeof(enemy);
	
	while(i--) {
		if (!ANNIE_D->check_buff(enemy[i],"lockup"))
			me->perform_action("dodge.canglongzhaxian");
		else if (random(2))
		{
			map_skill("sword","sharen-sword");
			me->perform_action("sword.sharenruma");	
		} else
		{	
			map_skill("sword","lefthand-sword");
			me->perform_action("sword.duxin");
		}		
		if (me->is_busy())	return 1;		
	}
	return 1;
}