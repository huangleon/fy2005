// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    	set_name("�޻�", ({ "master wu", "master"}) );
    	set("nickname", HIM "��ɮ"NOR);
    	set("gender", "����" );
    	set("age", 29);
    	set("per", 55);
    	set("int",30);
    	set("attitude","friendly");
    
    	
    	set("long", " ���°��࣬һ����Ⱦ���������ϵ�΢ЦҲ�г���֮�⡣\n");
    	create_family("������", 16, "��ʦ");
    	set("class", "shaolin");
    	    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	name()+"����һ��һ���Ϊ��ʦ��衣����\n",
            	name()+"�������������ˣ������Ҿ�˵����Ψһ���ƻ�����ƻ��ľ����㡣\n"
            }) );
            
    	set("combat_exp", 5000000);
    	set("reward_npc", 1);
    	set("difficulty", 10);   
    	
    	set_skill("move", 200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("literate", 200);
    	set_skill("unarmed",200);
    	set_skill("puti-steps",200);
    	set_skill("yiyangzhi",200);
    	set_skill("buddhism",250);
    	set_skill("chanting",200);
    	set_skill("xiaochengforce",200);
    	set_skill("staff",200);
    	set_skill("parry",200);
    
    	map_skill("parry","yiyangzhi");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "yiyangzhi");
    	map_skill("move", "puti-steps");
    	
    	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	  (: perform_action, "unarmed.qiankun" :)
        }) );
    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
}

void attempt_apprentice(object me)
{
    	command("shake");
    	command("say �ҳ����������⣬�㻹��ȥ�ҷ��ɰɡ�\n");
}


void init()
{
		if (interactive(this_player()))
			call_out("confess",1,this_player());
		::init();
}

int confess(object me)
{
		if (!me || environment(me)!= environment())	return 1;
		
		if (REWARD_D->riddle_check(me,"����֮��") != 9 || 
			! REWARD_D->check_m_success(me, "���˵ı���"))
		{
			return 0;
		}
		REWARD_D->riddle_set(me,"����֮��",10);
    	ccommand("say ������ʲô��֪���ˡ�����\n");
    	ccommand("say ����������û�ң���\n");
		kill_ob(me);
		return 1;
}

void die()
{
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
			if(owner=killer->query("possessed"))
				killer = owner;
			me = killer;

		if (REWARD_D->riddle_check(me,"����֮��") == 10)
		{
			REWARD_D->riddle_set(me,"����֮��",11);
	    	ccommand("emote ��ɫ���壬�е���������");
	    	ccommand("say ��ɱʦ������Ϊ������\n");
			message_vision(HIC"\n\nһ�ѳ���ͻȻ����Ļ��ֱ�����룬��ƫ���еش���$N�Ŀڡ�\n"NOR,this_object());
			message_vision(HIW"$N�͵���ͷ���������ŵؿ�����ǰ�������૵����ݣ������ݣ�����\n\n"NOR,this_object());
			tell_object(me,YEL"�޻����ˣ�������ǰ������ȴ��������ǻ���ɢ������\n");
//			REWARD_D->riddle_done(me,"���ַ粨",10,1);
		}
		}		
		::die();
}



int accept_object(object who, object ob)
{
	string msg;
	
	if(ob->query("name")!="���ʳ���") return 0;
	if (REWARD_D->riddle_check( who, "���˵ı���") == 2)
//	if (who->query("���_quest2")=="�ɹ�")
	{
		msg=HIG"�޻��ٺ���Ц���������Ϲ���Ǽһﶼ������˭�����Һ���ĸ�׵İ�ҵ��
����������Ҳ��������\n"NOR;
		REWARD_D->riddle_set( who,"���˵ı���",3);	
//		who->set("���_quest3","�ɹ�");
	}
	else
		msg=HIM"�޻�ü���������Цһ����������������Ϲ�һͬ�ϻ�Ȫ�ɡ���\n"NOR;
	message_vision(msg,who);
	kill_ob(who);
	return 0;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/



