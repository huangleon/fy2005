#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("������",({"huo ji","huoji"}));
	set("title","���ׯ");
   	set("long","
����Ե�û����ɵ����ӣ�ֻϣ�����ڣ������ڵ�����Ȼ�ǻ�ƣ�
�ڼ���ȴ���ϰ塣\n");
     	
     	set("gender","����");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",1000000);  
    	set("age",42);
    	 	
    	set("int",40);
    	set("cor",40);
    	set("cps",40);
    	   	
    	set("inquiry", ([
        	
	   	]));

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"�е��������˰���ǿ����������������\n",

        ]) );    	
        
    	set("chat_chance",1);
    	set("chat_msg",({
			name()+"˵�����͹پ���������������������\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","tianlongwhip",1);
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/weapon/whip",([	"name": "Ƥ��",
    						"long": "һ�������ϵ�Ƥ�ߡ�\n",
    						"value": 1,
    						 ]))->wield();    
}

