
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("�ļ�", ({ "master jian", "master"}) );
        set("gender", "����" );
        set("class", "shaolin");
        set("age", 44);
		set("per", 35);
		set("attitude","friendly");
        
        set("long","\n");
        create_family("������", 17, "����");
        
        set("combat_exp", 1200000);
        
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("unarmed",160);
		set_skill("puti-steps",150);
		set_skill("dabei-strike",150);
		set_skill("xiaochengforce",100);
		set_skill("parry",150);
	
		map_skill("parry","dabei-strike");
        map_skill("dodge", "puti-steps");
		map_skill("force", "xiaochengforce");
		map_skill("unarmed", "dabei-strike");
	
    	set("chat_chance", 15);
    	set("chat_msg", ({
			"���ص������󷭷��ҷ�������������������������\n",
			"���ص��������������þ���У���\n",
        	(: getting :)
    	}) );
        
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
            (: getting :),
            (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/skinmask")->wear();
	carry_object("/obj/armor/cloth")->wear();
}


void hide()
{
	object *inv;
	int i;
        if( !environment() ) return;
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
		if (REWARD_D->riddle_check(inv[i],"�ؾ�¥") == 1)
			REWARD_D->riddle_set(inv[i],"�ؾ�¥",999);		// failed
	message_vision("$N��Цһ���������˾��飬���ű��ĺ���ƨ�ɰɣ���\n",this_object());
	message_vision("$NһԽ���������ڲ����ˣ�����\n",this_object());
   	destruct(this_object());
}


void getting()
{
	command("get jingshuhe");
	call_out("hide",10+random(20));
}

void unconcious()
{
	die();
}

void die()
{
        int i;
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
				if(owner=killer->query("possessed"))
					killer = owner;

				me = killer;
				if (REWARD_D->riddle_check(me,"����֮��") == 3 && REWARD_D->riddle_check(me,"�ؾ�¥") == 1)
					REWARD_D->riddle_set(me,"�ؾ�¥",2);

				message_vision("$N���Ʋ�����������"YEL"����"NOR"��Խ��������ʧ������\n",this_object());
				move(load_object("/obj/void"));

				me=find_object("/d/shaolin/changjing5");
				if (!me)
					me=load_object("/d/shaolin/changjing5");
				me->init();

		}
        ::die();

}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


