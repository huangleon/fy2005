#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("���",({"feng hao","feng"}));
	set("title","�Һ���ʵ");
   	set("long","
����Ǿջ�԰������һ��ƽ����ʵ������˵������������������ֻҪ
�ϲ�һ�����£����������������ٶȴ�����ǣ��һƥ��װ�����Ŀ���\n");
     	
     	set("gender","����");
     	set("group","juhua");
     	
    	set("age",42); 	 	
    	
    	set("combat_exp",3500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({

    	}) );    	    	
    	
	auto_npc_setup("wang",180,200,0,"/obj/weapon/","fighter_u","thunderwhip2",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 	carry_object("/obj/weapon/whip",([	"name": "������",
    						"long": "һ�������ޡ�\n",
    						"value": 0,
    						 ]))->wield();    
}

