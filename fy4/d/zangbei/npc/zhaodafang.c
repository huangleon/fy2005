#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("�Դ�",({"zhao dafang","zhao","dafang"}));
   	set("long","
һ������Т�������ˡ����޵ú����ġ��������ϵ�ֽ��ֽ��ֽ�����£�
�����˻��۾��ﻹ�����ᡣ\n");
     	set("gender","����");
    	set("age",32);
    	 	
    	set("combat_exp",5100000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"�Դ󷽽����ϵ�ֽ��ֽ��ֽ�����£������˻��۾��ﻹ�����ᡣ\n",
    	}) );    	    	
    	
	  	auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","scratmancy",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": WHT"������"NOR,
    						"long": "һ�������ۡ�\n",
    						 ]))->wear();    
    
}
