//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("�ζ�", ({ "meng er" }) );
        set("gender", "Ů��");
        set("age", 26);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"�ζ����������ڵ��ϣ��ֿ�ʼ������ˡ�\n",
	}) );

        set("attitude", "friendly");
        set("title",HIR"����"NOR);
        set("nickname", HIG"���ﻨ��֪����"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","legend");
        set("death_msg",CYN"\n$N̾�����������������Σ�Ҳ��ʧΪһ�����ʵ��¡�\n"NOR);
        set("combat_exp", 12000000);        
        
    set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
    set("perform_busy_d1", "legend/dodge/fall-steps/qiufengluoye");
		set("perform_weapon_attack", "npc/sword/zensword/menghuankonghua");

		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("cloudforce", 180);
		    set_skill("fall-steps", 180);
		    set_skill("zensword", 200);
        set_skill("zen", 180);
        set_skill("dabei-fu", 200);
        set_skill("xiaodao", 180);
        set_skill("six-sense", 200);
        
        map_skill("unarmed","dabei-fu");
        map_skill("force", "cloudforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","zensword");
        map_skill("sword","zensword");
        setup();
    	carry_object("/obj/weapon/sword",([	
    						"name":  MAG"���ﻨ��"NOR,
    						 ]))->wield();  

    	carry_object("/obj/armor/cloth",([	
    						"name":  "��֮��",
    						 ]))->wear();  

}

