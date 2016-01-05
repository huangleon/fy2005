inherit SMART_NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack();

void create()
{
        set_name("����˪", ({ "leng qingshuang","leng" }) );
        set("title",HIG "���㱤" NOR);
        set("gender", "Ů��");
        set("age", 28);
        set("long",
"һ���ֳ�������ɡ�İ���Ů�ӡ�\n");
       
        set("chat_chance", 1);
		set("chat_msg", ({
	 	"����˪���ų���̾Ϣ�������ã��ѵ���Ҳ�����˴������µĵ��ӣ�
�ѵ���û�п�������ҵİ�������\n",
	}) );
       
        set("attitude", "friendly");
        set("score", 200);
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 1);
        
        set("combat_exp", 2000000);        
        set("per",50);
        
		set("perform_busy_d", "huashan/dodge/cloud-dance/yexuechuji");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        set_skill("sword",150);
        set_skill("cloud-dance",180);
        set_skill("anxiang-steps",180);
        set_skill("qingfeng-sword",180);            
        set_skill("hanmei-force", 150);
        set_skill("zhaixin-claw",140);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("sword","qingfeng-sword");
        map_skill("parry","qingfeng-sword");
        map_skill("dodge","cloud-dance");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/armor", 30);
        setup();

        carry_object("/obj/weapon/sword")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

