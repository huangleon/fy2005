//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("��Ȼ", ({ "tian ran" }) );
        set("gender", "Ů��");
        set("age", 24);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"��Ȼ���ڵ��ϳճյ��������ϣ���֪������Щʲô��\n",
	}) );

        set("attitude", "friendly");
        set("title",HIG"β��"NOR);
        set("nickname", HIY"������ƾ�����"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","legend");
        set("combat_exp", 12000000);        
		    set("group", "couple");
		set("perform_unarmed_attack", "taoist/spells/necromancy/feeblebolt");
		set("perform_unarmed_attack2", "taoist/spells/necromancy/demonicbolt");
	  set("perform_unarmed_attack3", "taoist/spells/necromancy/thunderstorm");	  
	  set("perform_unarmed_attack4", "taoist/unarmed/tenderzhi/qiankun");	
		
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
	      set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("iron-cloth", 150);
        set_skill("yijinjing", 200);
        set_skill("perception", 200);
        
	    set_skill("tenderzhi", 200);
	    set_skill("gouyee", 200);
	    set_skill("notracesnow", 200);
	    set_skill("snowshade-sword", 200);
	    set_skill("taoism", 220);
	    set_skill("necromancy", 200);
	    set_skill("scratmancy",200);
	    set_skill("scratching",200);
	    
	    map_skill("spells", "necromancy");
	    map_skill("unarmed", "tenderzhi");
	    map_skill("parry", "snowshade-sword");
	    map_skill("sword", "snowshade-sword");
	    map_skill("move", "notracesnow");
	    map_skill("dodge", "notracesnow");
	    map_skill("force","gouyee");
	    map_skill("iron-cloth","yijinjing");
        setup();


       	carry_object("/obj/armor/cloth",([	
    						"name":  "β֮��",
    						 ]))->wear();  

}
