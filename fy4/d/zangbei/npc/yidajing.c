#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("�״�",({"yi dajing","yi","dajing"}));
	set("title","���־���");
   	set("long","
һ������Т�������ˡ����޵ú����ġ��������ϵ�ֽ��ֽ��ֽ�����£�
�����˻��۾��ﻹ�����ᡣ\n");
     	set("gender","����");
    	set("age",52);
    	 	  	
    	set("combat_exp",7500000);  
    	set("attitude", "friendly");
    	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","alchemy",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword",([	"name": "�彣",
    						"long": "һ�Ѻܳ����ĳ�����\n",
    						 ]))->wield();    
    
}
