// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int init_quest();

int leave();
void create()
{
    	set_name("�Ϲ���", ({ "master nangong", "master"}) );
    	set("nickname", HIR "����"NOR);
    	set("gender", "����" );
    	set("class","beggar");
    
    	set("reward_npc", 1);
    	set("difficulty", 5);
    
    	set("age", 34);
    	set("per", 35);
    	set("attitude","friendly");
    
    	set("long", "�������µ�һ���İ�����ǰ�ϰ����δȵİ�ͽ��\n");
    	create_family("ؤ��", 7, "��ͷ����");
    	set("rank_nogen",1);
    	
		set("ranks",({"�������","һ������","��������","��������","�Ĵ�����","�������","��������",
			"�ߴ�����","�˴�����","�Ŵ�����","��������","��������",WHT"����������"NOR,
			WHT"����������"NOR,WHT"������"NOR,HIW"��ͷ���"NOR}));
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.xianglongwuhui" :),
             }) );

    	set("combat_exp", 2000000);
    	
    	set("chat_chance",2);
    	set("chat_msg", ({
			"�Ϲ�����������ֻ��ɫ���Ÿ룬������˼��\n"
        }) );
            
    	set_skill("perception", 100);
    	set_skill("move", 150);
    	set_skill("parry",150);
    	set_skill("dodge", 150);
    	set_skill("force", 160);
    	set_skill("literate", 100);
    	set_skill("unarmed",160);
    	set_skill("doggiesteps",150);
    	set_skill("dragonstrike",160);
    	set_skill("huntunforce",140);
    	set_skill("staff",200);
    	set_skill("dagou-stick",150);
    	set_skill("begging",150);
    	set_skill("foreknowledge",150);
    	set_skill("chanting",100);
    	
    	map_skill("dodge", "doggiesteps");
    	map_skill("force", "huntunforce");
    	map_skill("unarmed", "dragonstrike");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dagou-stick");
    	
    	
	    set("inquiry", ([
	        "�Ÿ�":			(: init_quest :),
	        "��ɫ���Ÿ�":	(: init_quest :),
	        "ıɱ" : "action�Ϲ��龪�ȵذ���һ��˵����֤��ô��\n",
	         "leave" : (: leave :),
	        ]));
    	setup();
    	carry_object(__DIR__"obj/9bagcloth")->wear();

}

int	init_quest(){
	object me = this_player();
	
	if (REWARD_D->check_m_success(me,"���ȵ��"))
	{
		command("say ��С�ӣ��ɵò�����");
		command("grin");
		if (me->query("class")=="beggar")
			command("say ���Ȼ��ɴ��£��������ҵ��״������ˣ������Ҳ�����߶���");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��"))
	{
		command("say �ҽ�������°������ˣ�");
		command("heng");
		return 1;
	}
	
	if (me->query_skill("begging",1) < 150)
	{
		command("sigh");
		command("say ��Ĺ��򻹲����ң�����ֻ�ǰװ�������");
		tell_object(me, WHT"��������Ҫ150������֮����\n"NOR);
		return 1;
	}	
	
	command("hmm");
	command("say ������ֶ�"YEL"�ɸ봫��"CYN"��Ҫ���������ȥЭ�����ҿ�����������Ҳ�����ˣ�
�ʹ����ܶ���һ�Σ���úã��������ͣ�");
	REWARD_D->riddle_set(me,"���ȵ��", 1);
	return 1;
}
	

void attempt_apprentice(object me)
{
    if((int)me->query("deposit")<=0)
    {
	command("say ������һƶ��ϴ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
	command("sigh");
        command("say ��������������з磬����Ǯ���Ƶģ�ΪʲôҪ������ؤ�");

    }
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "beggar");
}

int accept_object(object who, object ob)
{
	if(ob->query("name")!="���ʳ���") return 0;
	if (REWARD_D->riddle_check( who, "���˵ı���") == 2)
	{
        message_vision(HIC"�Ϲ����Ц�Ŷ�$N�������⵶���Ҵ�磡��\n"NOR,who);
		return 0;
	}
	if (!REWARD_D->riddle_check( who, "���˵ı���")) 
	{
		message_vision(HIR"�Ϲ�����ɫһ�䣬˵������С�ӣ�ֻ�ù���֪����̫���ˡ�������\n"NOR,who);
		kill_ob(who);
		return 0;
	}
    message_vision(WHT "�Ϲ���һ��Ĩ�����ᣬ���������úúã����Ҹ����Ɑ���ͺʹ��
һ��ȥ�������˼ҽӻ�����\n"NOR,who);
	message_vision(WHT"\n�Ϲ��齫���ʳ�������$N��\n"NOR,who);
    tell_object(who,"�Ϲ�������˵�����ͷ�����֪ͨ����޻������������ֳ���Ϊɮ��\n");
	tell_room( environment(), "�Ϲ�����"+who->name()
		+ "����С����˵��Щ����\n", ({ who, this_object() }) );
	REWARD_D->riddle_set( who, "���˵ı���",2);		
	return 0;
}


int leave() {
	if (this_player()->query("class")!="beggar") return 0;
	message_vision(CYN"$N̾�˿����������㵽����̰ͼ����ѽ����\n"NOR, this_object());
	message_vision(CYN"$N˵���򹷰����ͻ���ľ�����ʦү�������ģ������˾�ѧ�����ˡ�\n"NOR,this_object());
	return 1;
}