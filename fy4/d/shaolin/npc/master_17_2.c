// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

int choice();
int do_answer(string arg);

void create()
{
    	set_name("��ü", ({ "master mei", "master"}) );
    	set("vendetta_mark","shaolin");
    	set("gender", "����" );
        set("reward_npc", 1);
		set("difficulty", 10);
    
    	set("age", 64);
    	
    	set("skill_public", 1);
    	set("attitude","friendly");
    	set("long","�������ߴ����֮һ��\n");
    
    	create_family("������", 17, "��ʦ");
    	set("student_title","����");
    	set("combat_exp", 7000000);
    	set("class", "shaolin");
    	set("skill_public",1);    	
    	set("inquiry", ([
    		"���" : (: choice :),
    		
    	]));
    	
    	set_skill("move", 160);
		set_skill("dodge", 160);
		set_skill("force", 180);
		set_skill("unarmed", 180);
		set_skill("parry",160);
		set_skill("chanting", 160);
		set_skill("literate", 100);
		set_skill("zen", 160);
		         
		set_skill("puti-steps",150);
		set_skill("xiaochengforce",150);
		set_skill("dabei-strike",150);
		
		set_skill("wuche-axe",170);
		set_skill("axe",200);
		
		map_skill("unarmed","dabei-strike");			
		map_skill("force","xiaochengforce");
		map_skill("dodge","puti-steps");
		map_skill("axe","wuche-axe");
		map_skill("parry", "wuche-axe");
    
		set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
		set("perform_weapon_attack","shaolin/axe/wuche-axe/sanbanfu");
		set("smartnpc_busy",1);	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        
    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
    	carry_object(__DIR__"obj/axe")->wield();

}

void attempt_apprentice(object me)
{
	message_vision(CYN"$N΢Ц���\n"NOR, this_object());
	return;
}

int choice()
{
	object me = this_player();
	
	if(me->query("family/family_name") != query("family/family_name") ||
	   	(me->query("family/master_name") != "�ĺ�" && me->query("family/master_name")!="��Ħ�����"))
	 {
	 	message_vision(CYN"$NЦ��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲ�᣿\n"NOR,this_object());
		return 1; 		
	 }
	
	if (me->query("marks/damoyuan1") == "xinmei"){
		message_vision(CYN"$NЦ�������ղ�����ʦֶ�ķ�ѧ���г�����������������̽��̽�֡�\n"NOR,this_object());
		return 1;
	} 
			
	message_vision(CYN"
$N˵������վ����ƣ�������֪�������࣬�������࣬�������࡯��
������ϰ�򳹸���������ʮ���꣬���ļ�����������С�ɣ�ֻ���ڷ�
��Ϊ�ϣ�ȴ�����Ϸ���ʦ�����ļ���֮����֮������ν����Ϊ�������
Ϊ����ʦֶ���Ƿ���ʦ�����أ�����޸���񣬴��Ǵ�ۣ����Ĳ���Ϊ
ʦ����ʦֶ���ģ����Ŀ������໥�д衣\n"NOR, this_object());
	tell_object(this_player(),"����Ħ��ɮ���������������Ƿ�ѡ��������üѧ�գ�answer yes/no��\n");
	tell_object(this_player(),"�������skills���ȿ�һ�´�Ħ��ɮ���书��\n");
	this_player()->set_temp("answer/damoyuan1",1);
	return 1;
}
	
int do_answer(string arg)
{
	
	if ( !this_player()->query_temp("answer/damoyuan1"))
		return 0;
	
	if (arg == "no")
	{
		this_player()->delete_temp("answer/damoyuan1",1);
		message_vision(CYN"$N΢΢һЦ���������\n"NOR, this_object());
	}
	else if (arg == "yes")
	{
		message_vision(CYN"$N˵�������ĽԿ࣬���ļ��֣�����Ը��ʦֶ���㡣\n"NOR,this_object());
		this_player()->set("marks/damoyuan1","xinmei");
		this_player()->delete_temp("answer/damoyuan1",1);
	}else
		tell_object(this_player(),"��ֻ��ѡ��ش�yes����no��\n");
	
	return 1;
}


void init()
{	
	::init();
	add_action("do_killing", "kill");
	add_action("do_answer", "answer");
}

int recognize_apprentice(object ob)
{
	if(ob->query("marks/damoyuan1") == "xinmei")
		return 1;        
}


int prevent_learn(object me, string skill)
{
     	int	betrayer, mylvl, lvl;

    	lvl = this_object()->query_skill(skill, 1);
    	mylvl = me->query_skill(skill, 1);
    	if( betrayer = me->query("betrayer") )
    	{
        	if( mylvl >= lvl - betrayer * 20 )
        	{
            	message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�\n"
                           "Ҳ��������$p��ǰ����ʦ�ŵ�����\n...��\n",
                	           this_object(), me );
            	command("say �� .... \nʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
            	return 1;
        	}
    	}
    	return 0;
}