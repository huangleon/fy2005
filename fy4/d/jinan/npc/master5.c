// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>

int nangong();
int leave();
int wuwu();

void create()
{
    	set_name("�δ�", ({ "master renci", "master"}) );
    	set("nickname", HIR "ǰ�ΰ���"NOR);
    	set("long", "�δ���ؤ���ǰ�ΰ�����ֻ���������ಡ����λ���Ϲ���\n");
    	set("gender", "����" );
    	set("class","beggar");
    
    	set("reward_npc", 1);
    	set("difficulty", 15);
    
    	set("age", 64);
    	set("per", 25);
    	    
    	set("attitude","friendly");
        	
    	create_family("ؤ��", 6, "ǰ�ΰ���");
    	set("rank_nogen",1);
    	
		set("ranks",({"�������","һ������","��������","��������","�Ĵ�����","�������","��������",
			"�ߴ�����","�˴�����","�Ŵ�����","��������","��������",WHT"����������"NOR,
			WHT"����������"NOR,WHT"������"NOR,HIW"��ͷ���"NOR}));
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));

    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.xianglongwuhui" :)
            }) );
   	
   		set("combat_exp", 4000000);
    
    	set_skill("unarmed",180);
    	set_skill("foreknowledge",200);
    	set_skill("advanced-unarmed",200);
    	set_skill("dodge",180);
    	set_skill("staff",300);
    	
    	set_skill("force", 160);
    	set_skill("move", 160);
    	set_skill("parry",160);
    	set_skill("literate", 100);
    	set_skill("perception",100);
    	set_skill("chanting",100);
    	
    	set_skill("begging",200);
    	set_skill("doggiesteps",200);
    	
    	set_skill("dragonstrike",170);
    	set_skill("huntunforce",150);
    	set_skill("dagou-stick",180);
    	    
    	set_temp("apply/dodge",200);
    	set("inquiry", ([
        	"�Ϲ���" : 		(: nangong :),
        	"nangong" : 	(: nangong :),
        	"��"	:			(: wuwu :),
        	"Ҷ����":	"action�δȽ���˫ü˵�������׾������Ϣ��\n",
    	]));
    
    	map_skill("dodge", "doggiesteps");
    	map_skill("force", "huntunforce");
    	map_skill("unarmed", "dragonstrike");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dragonstrike");
    	map_skill("move","doggiesteps");
    	
    	setup();
    	carry_object(__DIR__"obj/9bagcloth")->wear();
	
	
}


void init(){
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
	    remove_call_out("greeting");
	    call_out("greeting", 2, ob);
	}
	add_action("do_killing", "kill");
	add_action("do_answer","answer");
}

void greeting(object ob){
	if( !ob || environment(ob) != environment() ) return;
	message_vision("\n$N��ΡΡ��̧��ͷ���˿�$n��̾�˿�����\n",	this_object(), ob); 
}

void attempt_apprentice(object me)
{
    	
    	if (REWARD_D->check_m_success(me,"���о�") && me->query("class")=="beggar"){
    		command("nod"); 
    		command("recruit " + me->query("id") );
    	} else {
			command("sigh");
        	command("say ���Ѿ������ǰ����ˣ����������ˣ��㻹��ȥ���Ϲ��ɣ�\n");
    	}
}

void recruit_apprentice(object ob){
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "beggar");
}

int nangong(){
	
	object me=this_player();
	
	if (!REWARD_D->check_m_success(me,"����ؤ��")
		||me->query("class")!= "beggar"  
		|| !REWARD_D->check_m_success(me,"���ȵ��")
		|| REWARD_D->riddle_check(me,"���о�"))
	{
		command("say �Ϲ�������ΪТ˳��ÿ������һ�룬��δ��ϣ�\n");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���о�"))
	{
		command("say �Ϲ��飬�ٺ٣��Ϲ��飡");
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"���о�"))
	{
		command("say �Ϲ���ֻ��һ��С�󣬹��ؤ����������������Σ�");
		return 1;
	}
		
		
	command("sigh");
	command("say ����б�ʿ�������֪�����Ϲ�Ұ�Ĳ��������Ұ���֮λ��������Ů��
��Ұ�Ĳ�������ͼ��˿ܹ��ᣬ�������֣�����֮�����õ���δ��ã�");
	me->set_temp("marks/a_renci",1);
	return 1;	
}	

int accept_object(object me, object ob)
{
		if(ob->name() == "�����ܺ�")
		{
			
			REWARD_D->riddle_done(me,"����ؤ��",5,1);
			
			if ( me->query("class")!= "beggar"  
				|| !REWARD_D->check_m_success(me,"���ȵ��"))
			{
				command("sigh");
				command("say ����������֪��������ȥ�ɡ�");
				return 1;
			}
			
			if (REWARD_D->check_m_success(me,"���ȵ��")==1){
				command("sigh");
				command("say ����б�ʿ�������֪�����Ϲ�Ұ�Ĳ��������Ұ���֮λ��������Ů��
��Ұ�Ĳ�������ͼ��˿ܹ��ᣬ�������֣�����֮�����õ���δ��ã�");
				me->set_temp("marks/a_renci",1);
				return 1;					
			}
		}
		return 0;
}		
			

int do_answer(string arg){
	
	object me= this_player();
	object room;
	if (!me->query_temp("marks/a_renci"))	return 0;
		
	if (me->query_temp("marks/a_renci")==1) {
		if (arg == "forgive" || arg == "��ˡ")
		{
			message_vision(CYN"$Nҡҡͷ˵����˿ɶԵ����Ȫ�µ�ԩ�꣡\n"NOR,this_object());
			return 1;
		}
		
		if (arg != "ɱ" && arg!="ɱ��" && arg !="kill") {
			command("sigh");
			command("shake");
			return 1;
		}
		
		message_vision(CYN"�δȵ�˫Ŀ��Ȼһ����ת˲��������ȥ��\n"NOR, me);
		command("say �Ϲ������ѷᣬóȻ���ֿ���ֻ�аװ�������\n");
		command("say ������֮�£�����һ����ɱ���ֿ��԰��ݣ���������֣�����
�����䣬��ͽ��Ѫ��֮�£�������Ƿ��������꣬���к��֮�£�");
		me->set_temp("marks/a_renci",2);
		return 1;
	}
	
	if (me->query_temp("marks/a_renci")==2)	{
		if (arg == "��")
		{
			command("say ����һ����һ�ˣ�˵��������");
			return 1;
		}
		
		if (arg == "û��")
		{
			command("say ���԰��ĺ�������һ���Ϲ����ͽ�ܣ�");
			message_vision(CYN"�δȵ�ͷ�������\n", me);
			return 1;
		}
						
		if (arg != "�岨" && arg!="Ԭ��" && arg!="qingbo" && arg!="yuanji"
			&& arg!="���ȵ��" 
			|| !REWARD_D->check_m_success(me,"���ȵ��")) {
			command("sigh");
			command("say �ɻ���������");
			return 1;
		}
		
		command("nod");
		command("say ����֪���£��岨Ԭ��������˴��ѡ�");
		command("say Ȼ��������һ���֣����ܿ������еĹ���ô��");
		me->set_temp("marks/a_renci",3);
		return 1;
	}
	
	if (me->query_temp("marks/a_renci")==3)	{
		if (arg != "��" && arg!="����") {
			tell_object(me,"\n��ֻ�ܻش��ܡ����ߡ����ܡ�\n");
			return 1;
		}
		if (arg == "��") {
			command("say ˵��������");
			me->set_temp("marks/a_renci",4);
			return 1;
		}
		if (arg =="����") {
			command("consider");
			command("say �ã������Ϸ�����һ��֮����");
			message_vision("�δ�һ����ȣ�˫�ƺϼƣ���ɽ������������$NϮ����
			
$N������Ϣһ�ϣ���ǰһ��ڡ�\n"NOR, me);					
			
			tell_object(me, WHT"
������Լ�����������������У������Ϥ����ף������Ϥ��������
�����Ϥ�ľ���ȴ�л���ʲôҲץ��ס��ʲôҲ�������С�������\n"NOR);

			REWARD_D->riddle_set(me,"���о�",1);
			me->delete("m_success/���ȵ��");
			REWARD_D->riddle_set(me,"���ȵ��",1);
			
			if (!room = find_object("/d/chenxiang/gaij"))
				room = load_object("/d/chenxiang/gaij");
			me->unconcious();
			me->move(room);
			return 1;
		}
	}
	
	message_vision(CYN"$N������ҡ��ҡͷ��������ϣ��������\n"NOR, this_object());
	me->delete_temp("marks/a_renci");
	return 1;
	
}	

int wuwu(){
	
	object me = this_player();
	
	if (REWARD_D->riddle_check(me,"���о�")!=2)	return 0;
	
	command("smile");
	
	
	command("say �����������, Ե��Եȥ�� Ե��Ե��");
	command("say �����˵ģ�����׷Ѱ...");
	command("say ��͸��, һ����ͷ, һ��΢Ц, �Ѿ���ʤǧ�����");
	command("say �������˼������������������뿪�����˷��ء�\n");
	command("say �Ϲ��������ϳˣ���������������ǿ���������������֮�ء�");
	command("say ��ʵ���ɷ��������������ˣ���Ҳ���ˣ������������ı��ǡ�");
		
	REWARD_D->riddle_done(me,"���о�", 50, 1);
	return 1;

}

