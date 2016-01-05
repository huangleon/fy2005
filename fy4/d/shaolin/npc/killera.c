// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit SMART_NPC;
#include <ansi.h>
void create()
{
        set_name("���������", ({ "figure leader"}) );
        set("nickname", HIG "ȭ������"NOR);
        set("gender", "����" );
        set("age", 41);
		set("per", 30);
        set("agi",25);
        set("class","beggar");
		set("attitude","friendly");
		set("bellicosity",30000);
	    set("figure_friend",1);
        
        set("long",
"���˵����ϴ��źڲ���ߣ���������Ŀ���������ݣ���ֻ���ƴ�ľ��ˡ���
�����˶����Ĺ�����������Ȼ����һ���˵����졣\n"
	);
        set("combat_exp", 5000000);
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		
        auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
		
}

void init()
{
        object ob;

        ::init();
        add_action("do_get","get");
        if( interactive(ob = this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
	object friend;
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	if (!ob->query("figure_friend"))
	{
			ccommand("say ��Ȼ�����Һ��£�����");
			ccommand("heng");
			ccommand("say ������·�㲻�ߣ���������Ͷ������");
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}


int do_get(string arg)
{
	if(!arg) return 0;
	message_vision("$NЦ����û����ô���˵��°ɣ�\n",this_object(),this_player());
	this_player()->perform_busy(1);
	return 1;
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
				if (REWARD_D->riddle_check(me,"����֮��") == 6)
				{
					REWARD_D->riddle_set(me,"����֮��",7);
					message_vision("������������ˡ�\n",this_object());
					tell_object(me,CYN"\n��������������´��п���֮����\n");
					tell_object(me,"�����صر�����̶��Ѩ��ȴ���������֮����ݲ���֮�ˣ�\n");
					tell_object(me,"һ���������������������£�����¥�׵���ɮ������������\n");
					tell_object(me,"��������������ĳ�������ʵ���졣\n");
					tell_object(me,"���еļ���·��Ǹ������Ԥ�ף��������ȥ������ʦ"YEL"�ر�"CYN"�ɡ�\n"NOR);
					move(load_object("/obj/void"));
				}

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


