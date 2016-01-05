inherit NPC;
#include <ansi.h>

int init_quest();

void create()
{
        set_name("�Ŷ�", ({ "zhang", "zhang en"}) );
        set("title", HIW "ؤ��ֶ����"NOR);
        set("gender", "����" );
        set("class","beggar");
        set("age", 34);
		set("attitude","friendly");
        set("long","ؤ��鲼���ϱ����Ŷ��������ڣ����������˷ֶ档\n");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 1000000);
        
       	set("inquiry", ([
	        "�ɸ봫��":	(: init_quest :),
	        "Э��":		(: init_quest :),
	        "����":		(: init_quest :),
	     	"Ԭ��":		(: init_quest :),
	     	"���о�":	(: init_quest :),
	     	"yuanji":	(: init_quest :),
	     	"qingbo":	(: init_quest :),
	     	"�岨����":	(: init_quest :),
	    	"ƭ��":		"��˵�˵�ʲô���ѵ���̰��������������ô��\n", 		
	     	"�׹���":	"��˵�����ǹ��и��֣�ǧ��Ҫ����������ͻ��\n",
	     	"�Ϲ���":	"�Ϲ���������ؤ�����ΰ�����\n",
	     	"ʧ��":		"��˵����ؤ����£�����û��ʧ�ܵģ�\n",
	     ]));
        
        
        set_skill("move", 100);
        set_skill("parry",120);
        set_skill("dodge", 120);
        set_skill("force", 180);
        set_skill("unarmed",150);
		set_skill("doggiesteps",200);
		set_skill("dragonstrike",150);
		set_skill("huntunforce",120);
        
        map_skill("dodge", "doggiesteps");
        map_skill("move","doggiesteps");
		map_skill("force", "huntunforce");
		map_skill("unarmed", "dragonstrike");

        setup();
        carry_object(__DIR__"obj/7bagcloth")->wear();

}


int	init_quest() {
	object me = this_player();
	object ob = this_object();
	object room, t1, t2, t3;
	
	if (REWARD_D->check_m_success(me,"���ȵ��")|| F_LEVEL->get_level(me->query("combat_exp"))< 61)
	{
		command("shake");
		command("sigh");
		tell_object(me,"���������������Ҫ�ȼ�61��\n");
		return 1;
	}
	
	if (me->query("class") == "beggar" && me->query_skill("begging",1)<150)
	{
		command("shake");
		command("sigh");
		tell_object(me,"��ؤ����ӽ��������150������֮����\n");
		return 1;	
	} 
	
	if (REWARD_D->riddle_check(me,"���ȵ��")== 1)
	{
		command("say �ɸ룿���ţ��ƺ�û������°���");
		command("?");
		command("say �����ܶ����ˣ������������һ������֮�¡�\n");
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��")<=2)
	{		
		command("say �����С������һ����÷��������£�Ԭ�����岨���ӡ���С
������������������û�ϵ��첻����Ը������ǰ�岨����֮�������˳�͢
�Թ�ɱͷ��ɱͷ�����ε����Σ�Ψ�岨����һ�����⡣��Ԭ����Ҳ������
�أ�������˶���Լ��\n");

		command("say ˭������������У�ǰ���չ�����׹����������ѡ��Ů����
Ȼ������Ԭ�������ϵ�ּ�⣬˭�ָ�Υ�����岨����һ������������ʲô��
������Ԭ��һ����Ů�ӣ�ȴ�������ӣ��׹���һʱҲ�޷���ʩ��\n");

		command("say ���죬����������������׹���������Ϊ�˶���Ԭ����ϣ����
���˺ڵ��ϵ�ɱ�֣����ձ㽫��ɱ�岨���ӡ�����ؤ������ݵô˵�����
����֮�¡�ֻ�������¶��ǳ������ϣ�������עĿ��\n");

		command("consider");

		command("say ����Ը����������ȥ�岨���Ӵ�����"YEL"������"CYN"\n");
		REWARD_D->riddle_set(me,"���ȵ��",2);
		
		if (REWARD_D->riddle_check(me,"���о�")==1)
			tell_object(me, WHT"\n�������һ���ƺ�����ô����Ϥ���ѵ����ֻص��˴�ǰ��\n"NOR);
		return 1;
		
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��")==3)
	{
		message_vision(CYN"$N����̾��������δ�ϣ�����ô��Ȼ�����ˣ����ˣ����ˣ�\n"NOR,ob);
		message_vision(YEL"����δ�䣬������������һ�����Ӱݵ������������岨������������ɱ�ˣ�\n"NOR, me);
		command("say �⡢�⡢�⡣����");
		command("slap "+ me->query("id"));
		REWARD_D->riddle_set(me,"���ȵ��",4);
		
		if (REWARD_D->riddle_check(me,"���о�")==1)
			tell_object(WHT"\n������������������������\n");
		
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"���ȵ��")==4)
	{
		command("say ���⣬���⣡�������ˣ�Ҳ�޷�����ˣ�");
		REWARD_D->riddle_set(me,"���ȵ��",5);
		return 1;
	}
	
	t1 = present("zhao neng");
	t2 = present("li feng");
	t3 = present("dai yin");
	
	if (REWARD_D->riddle_check(me,"���ȵ��")==5)
	{
		if (!t1 || !t2 || !t3)
		{
			command("say ���⣬���⣡�������ˣ�Ҳ�޷�����ˣ�");
			return 1;
		}
		
		command("say ֻ�ǣ�Ԭ�������׹������С�����");
		message_vision(CYN"$Nһ�����ӣ��ɴ࣬ɱ��ȥ��Ԭ������������\n"NOR, t1);
		message_vision(CYN"$Nҡҡͷ���׹����书��ɲ⣬�˼����򲻿ɡ�\n"NOR,t2);
		message_vision(YEL"\n$N��Ȼ�յ�$n���ԣ����ĵ���$n����˵�˼��仰��\n"NOR, t3, ob);
		
		REWARD_D->riddle_set(me,"���ȵ��",6);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"���ȵ��")==6)
	{
		message_vision(YEL"$N������𣬻��Ƶ������˼������\n"NOR,ob);
		
		tell_object(me, CYN"
�Ŷ���������֮�������Ǿȳ�Ԭ������ֵ���һ�������֮�ƣ����������������\n"NOR);
		REWARD_D->riddle_set(me,"���ȵ��",7);
		
		
		if (REWARD_D->riddle_check(me,"���о�")==1)
			tell_object(me,WHT"\n���⡢���Ǹ�"YEL"ƭ��"WHT"��������Ŷ�����\n"NOR);
			
		return 1;
	}
	if (REWARD_D->riddle_check(me,"���ȵ��")>=7	)
	{
		command("say ��ô�������ﵢ�飡");
		return 1;
	}
}
	
		
int accept_object(object me, object ob)
{
		if (ob->query("name")=="���ɢ" && ob->query("real")
			&& REWARD_D->riddle_check(me,"���ȵ��")==10)
		{
			tell_object(me,CYN"�Ŷ�˵���ã�������¾㱸������ǲ�˰���֪ͨԬ���
������ǰȥ�������ɢ����Ԭ���\n"NOR);
			ob->set("real",2);
		}
		return 0;
}		
			
			
	
	
	
	
	
	