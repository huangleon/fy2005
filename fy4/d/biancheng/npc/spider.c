#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("����֩��",({"feitian zhizhu","feitian","zhizhu" }));
    	set("long","��������֮�죬����֮�ܵ������治����ϸ����˿���������硯
��˸��֡�\n");
     	set("gender","����");
    	set("age",32);
    	 	
    	set("combat_exp",5200000);  
    	set("attitude", "friendly");
    	    	
    	set("reward_npc",1);
    	set("difficulty",3);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(90) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"����֩�����������һʱ��Ϸ��ǧ��ˡ���\n"
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","fy-sword",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "�̴�װ",
    						"long": "һ���̴�װ��\n",
    						 ]))->wear();     
    
}
