#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("���ϴ�",({"jiao laoda","jiao","laoda"}));
	set("title","��ʦ");
   	set("long","
���ϴ�����ʦ��������һ��������һ��������ȫ�����������öȹ�
�ģ����ѽ���һ���������£�ȫ����ĥ���������е����ϡ�����
��˫������������Ҳ����Щ���ˣ�һ˫�������������۾��ѱ��Ӿ��ݵ�
���졣ÿ����˯��������Ӳ��ľ���ϸ������Լ������ϵ��ϼ�ʱ����Ҳ
���뵽��ȥ��һ������������û�б�ĵط���ȥ����Ϊ���ĸ�Ҳ����
�����á�\n");
     	set("gender","����");
    	set("age",52);
    	 	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(80) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","thunderwhip2",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/weapon/whip",([	"name": "�����",
    						"long": "һ����������ޡ�\n",
    						"value": 0,
    						 ]))->wield();    
}
