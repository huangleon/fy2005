#include <ansi.h>
inherit SMART_NPC;
inherit F_MASTER;

void create()
{
    	set_name("ԭ����", ({ "master yuan suiyun", "yuan suiyun","master"}));
    	set("long","
��Ц����������У���һ˫�۾��ȴ������˵�����Ŀ��顢��į������
֮��, �Ǹ�����������˹�ĵ����꣬�����仪������ȴ������\n");
    	set("title","����ɽׯ������");
    	set("nickname", HIR "������"NOR);
    	set("gender", "����");
    	create_family("����", 1, "����");
    	set("student_title","����");
    	set("score_cost",20000);
    	
    	set("class","bat");
    	set("reward_npc", 1);
    	set("difficulty", 25);
    	set("fly_target",1);
    	
    	set("age", 26);
    	set("per", 40);
    
    	set("combat_exp", 10000000);
    	set("attitude", "friendly");
    	
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(10) :),
        }) );
        
    	set("chat_chance", 1);
    	set("chat_msg", ({
        "ԭ�����ߵ��ٱߣ�һ����������ˮ������Ӵ���ָ�������
���伺�кܾ�û�й�����ö��������ˡ�\n ",
            "\n",
        }) );
        
	    set_skill("unarmed", 200);
	    set_skill("move", 200);
	    set_skill("dodge", 250);
	    set_skill("parry", 250);
	    set_skill("force", 180);
	    set_skill("blade", 200);
	    set_skill("meng-steps", 220);
	    set_skill("bat-blade", 160);
	    set_skill("wuzheng-force", 220);
	    set_skill("perception",250);    
	    
    
    	map_skill("force", "wuzheng-force");
    	map_skill("move",  "meng-steps");
    	map_skill("dodge", "meng-steps");
    	map_skill("parry", "bat-blade");
    	map_skill("blade", "bat-blade");

    	set("ranks",({"����","Са","��а","������","��ȸ��","�׻���",
                      "������","������"}));
    	set("rank_nogen",1);

    	setup();
    	carry_object(__DIR__"obj/armor"	)->wear();
    	carry_object(__DIR__"obj/hanhai")->wield();
}

void attempt_apprentice(object ob)
{
    	
        command("say  ���²�����ͽ��");
	return;
    	
}

