#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��", ({ "dahan" }) );
        set("gender", "����");
        set("age", 32);
        set("long","һ�����δ󺺴���������������ŷ�����ȥ����ȸ��\n");
		set("combat_exp",60000);
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������֦�Ȼ��˼��£��ִ����������ˡ�\n",
                "��˵�����Ľ��أ�һ׼�����ڼ����ˡ�\n",
        }) );

	set("inquiry", ([
        	"Сϱ����": "��ϱ�����ڼҸ����շ��ء�\n",
        	"�ؼ�": "action�󺺴��������ţ��ƺ�û��������ʻ���\n",
        	"�ع�":	"�����»飬����ع��أ�\n",
        	"��":	"�԰��Ĺ�����û���ǰ�������ϵ�Ѿ������ˣ����ţ��������Ҹ���Ȼ��Ȼ���\n",
        	"����":	"�԰��Ĺ�����û���ǰ�������ϵ�Ѿ������ˣ����ţ��������Ҹ���Ȼ��Ȼ���\n",
        	"��֦":"�԰��Ĺ�����û���ǰ�������ϵ�Ѿ������ˣ����ţ��������Ҹ���Ȼ��Ȼ���\n",
         ]) );
         
		set_skill("sword", 50);
		set_skill("three-sword", 50);
		set_skill("dodge", 50);
		set_skill("move", 50);
		set_skill("five-steps", 50);
		set_skill("parry",50);
		
		map_skill("parry","three-sword");
		map_skill("sword", "three-sword");
		map_skill("dodge", "five-steps");
		map_skill("move", "five-steps");
	
		set("can_carry",1);
        setup();
        set_temp("apply/damage",30);
		carry_object(__DIR__"obj/shuzhi")->wield();
		carry_object("/obj/armor/cloth")->wear();
}


int accept_object(object who, object ob)
{
	object		shu;
	if( ob->name() == "����") {
		message_vision(CYN"��һ����˵�����԰����书�����Ѳ���Ҫ��Щ��ͭ�����ˡ���\n"NOR,who);
		message_vision(CYN"��˵����λ"+RANK_D->query_respect(who)+"����Ҳ��������ˣ��������Ȼ��Ȼ���\n"NOR,who);	
		full_me();
		set_temp("going_home",1);
		command("fight "+ who->query("id"));
		return 0;
	}
	return 0;
} 

void win_enemy(object loser)
{
    	command("say �������ҿ�������ֻ�Ǹ���֦����Ȼ��������\n");
    	delete_temp("going_home");
}

void lose_enemy(object winner)
{
	object	shu;
	string msg;
	
	if (query_temp("going_home")) {
		msg = CYN"
�󺺳�̾һ������ϱ����˵�ò�������������ֻ�Ǹ��ֵص�����������
�����ǻؼ�ů��ͷ�ɡ���"NOR;
		if (shu = present("shu zhi", this_object())) {
			shu ->move(environment());
			msg += CYN"����һ�ɣ���֦���ڵ��ϡ�"NOR;
		}
		msg += CYN"��һƨ�����ڵ��Ϸ��������\n"NOR;
		message_vision(msg, winner);
    		if (QUESTS_D->verify_quest(winner,"�䵱��")) 
    			QUESTS_D->special_reward(winner,"�䵱��");		
    	}   		
}