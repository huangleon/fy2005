//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("ϸ��", ({ "xi yu" }) );
        set("gender", "Ů��");
        set("age", 23);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("title",BLK"����"NOR);
        set("nickname", CYN"б��"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","legend");
        set("death_msg",CYN"\n$N̾�����������������Σ�Ҳ��ʧΪһ�����ʵ��¡�\n"NOR);
        set("combat_exp", 12000000);        
        set("group", "tiexue");
        set("npc_team", "��������");

    set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
    set("perform_busy_u1", "legend/unarmed/meihua-shou/wuzhanmei");
    set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
    set("perform_busy_d1", "legend/dodge/fall-steps/qiufengluoye");
		set("perform_weapon_attack", "legend/sword/diesword/caidiekuangwu");
		set("perform_weapon_attack1", "legend/sword/diesword/daojianruomeng");
		set("perform_buff_1", "legend/force/qidaoforce/juli");
		set("perform_buff_2", "legend/force/qidaoforce/jushen");
		set("perform_buff_3", "legend/force/qidaoforce/juqi");
		
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
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
        
        set_skill("qidaoforce", 180);
        set_skill("fall-steps", 200);
		    set_skill("diesword", 200);
		    set_skill("six-sense", 300);
        set_skill("dormancy", 300);
        set_skill("meihua-shou", 200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        setup();
    	carry_object("/obj/weapon/sword",([	
    						"name":  HIY"��ӳ"NOR,
    						
    						 ]))->wield();  

    	carry_object("/obj/armor/cloth",([	
    						"name":  "��֮��",
    						 ]))->wear();  
}

