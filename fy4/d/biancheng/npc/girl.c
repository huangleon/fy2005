#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("���۾���С����",({"little girl","girl"}));
   	set("long","@@@@@@@@@@@@@@@@@@@@@\n");
     	set("gender","Ů��");
    	set("age",16);
    	 	
    	set("int",22);
    	set("cor",30);
    	set("cps",20);
    	
    	set("combat_exp",600000);  
    	set("attitude", "friendly");
    	    	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"���۾���С��������ͷ��������շ�����\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","qingfeng-sword",1);
		setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  HIG"�黨�̶�С��"NOR,
    						"long": "һ���̶�С�ӣ�����������������ż���С����\n",
    						 ]))->wear();    
    
}
