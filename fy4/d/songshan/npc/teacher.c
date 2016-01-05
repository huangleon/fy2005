// teacher.c
#include <ansi.h>
inherit NPC;
int quest();

void create()
{
		set_name("�λ�", ({ "meng huan", "huan" }) );
        create_family("������", 20, "����");
		set("title", "��������");
		set("class", "shaolin");
        set("vendetta_mark","shaolin");
		set("int",5);
        set("skill_public",1);
		set("gender", "����" );
		set("age", 57);
        set("chat_chance", 2);
        set("inquiry", ([
        	"����":	(: quest() :),
        	"����֮��": "��������ֵ����֮��ؾ���"YEL"���鱻��"CYN"\n",
        	"���鱻��": "�����¾��鱻��������������������ȥ�����ɡ�\n",	
        	"������": "�����¾��鱻��������������������ȥ�����ɡ�\n",	
        	"�ؾ�¥": "�����¾��鱻��������������������ȥ�����ɡ�\n",	
        ]));	
        
        set("chat_msg", ({
                "�λ��ֹ���������֪����˭͵�˱��µľ��飿��\n",
        }) );
		set("long","
�λ�ԭ���ϣ�����ʱ�й���ţ������ǳ��صĸ�ĸ�٣������ڼ��������ɰ���
��ϧΪ�������ɣ���;���������ڿ��ƺ쳾������Ϊɮ���λ���ͨ����ʶ�֣�
�������Ŀ�������̣�apprentice����\n");
				
		set("attitude", "peaceful");
		set_skill("literate", 150);
		setup();
		carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object ob)
{
    	command("say Сɮ�޵����ܣ��θ���ͽ��");
		command("say ����������ʩ����ѧ����ʶ�֣�Сɮ������ʩ�����㡣\n");
		return; 	
}

int quest() {
		object ob = this_player();
		
		command ("say ��������ֵ����֮��ؾ���"YEL"���鱻��"CYN"��Сɮ�ܷ���֮����ɽ̽�á�");
		if (!REWARD_D->check_m_success(ob,"����֮��") && !REWARD_D->riddle_check(ob,"����֮��"))
			REWARD_D->riddle_set(ob,"����֮��",1);
        return 1;
}


int recognize_apprentice(object ob)
{
	if(ob->query("free_learn/literate"))
		return 1;
    else {
		if(REWARD_D->check_m_success(ob,"�ؾ�¥")) 
		{
			command ("say �ã��ã���Ϊ�������˴󹦣������Ըѧ���飬Сɮ������������\n");
			ob->set("free_learn/literate", 1);
			return 1;
		}
        	command ("say ��������ֵ����֮��ؾ���"YEL"���鱻��"CYN"��Сɮ�ܷ���֮����ɽ̽�ã�
����δ�ˣ�Сɮʵ����Ͼ�˼�ʫ��֮�¡�");
			if (!REWARD_D->check_m_success(ob,"����֮��") && !REWARD_D->riddle_check(ob,"����֮��"))
				REWARD_D->riddle_set(ob,"����֮��",1);
        	return 0;
	}
}
