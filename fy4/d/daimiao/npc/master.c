inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    	set_name("�����", ({ "master yu", "master"}) );
    	set("nickname", HIR "��ʤ��ħ"NOR);
    	set("gender", "����" );
    	set("age", 64);
    	set("per", 3);
    	set("reward_npc", 1);
	set("difficulty", 25);
	set("group", "demon");
        set("vendetta_mark","demon");
    	set("attitude","friendly");
    
    	set("combat_exp", 12000000);
    	set("score", 200000);
    	set("max_force", 5000);
    	set("force", 5000);
      	
    	set("long","
���������ǽ����������������ɣ���һ����ѩ�׷ɵ����ϣ����õ�����
�������������ʮ�����������ص�����÷�����⡣������ȥ�ˣ������к�Ȼ
����һ�����ص�������̣����������������еĽ�������������˭Ҳ�������
Ҳû�˸��ʡ������ʹ���֪��������������˶��������׵���ʧ�ˡ�ֻ�Ǵ�˵��
����һ�ֵ�����Լ�е����񵶵����ϡ�\n");
    
    	create_family("�������", 1, "����");
    	set("rank_nogen",1);
    	set("ranks",({"��ͽ","������","����","��̳��","̳��",
                      "������","����","����","�󻤷�",
                      "����","����","������"}));
    	set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,15000000 }));

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(90) :),
        }) );
        
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","demon-blade",2);
    	
    	setup();
    	carry_object(__DIR__"obj/wufu")->wear();
    	carry_object(__DIR__"obj/lou")->wield();

}

void attempt_apprentice(object me)
{
    	command("say �Ϸ��ͽ������ʮ��ǰ���ѱ����Ϸ��㲻���ٳ��������ˡ�");
    	return;
}


int accept_object(object me, object obj)
{
    	if(obj->query("for_bandit"))
    	{
		command("? "+me->query("id"));
        	command("say �㣮����ɱ�˱��̵��ˣ�͵�˱��̵Ķ�������������Ū�Ϸ�\n");
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		return 1;
    	}
    	if(obj->query("for_bandit2"))
    	{
		command("smile");
		command("say �ã��ܺã�����������ʮ�꣬�Ϸ������Ϊͽ�ˡ�\n");
		return 1;	
    	}
    	return 0;
}
