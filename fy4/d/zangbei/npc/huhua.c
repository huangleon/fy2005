#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();

void create()
{
    	set_name("�ػ���",({"qin huhua","qin"}));
	set("title","³��");
   	set("long","
�ػ�����³��������ҵ���һ�����ˣ�����Ѵ���㹻����������Ů����
�����������廹�Ǳ����úܺã��������Ǻܳ��棬����ÿ�����죬����Ҫ
����������һ�����ӡ��ػ��������ֵĵ�λ�����ͣ��ѿ��뵱���κ�����
�������˷�ͥ����\n");
   	
     	set("gender","����");
     	set("group","khlr");
     	
    	set("age",62); 	 	
    	    	
    	set("combat_exp",4800000);  
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
		"�ػ���Ц�������Ϸ��ķ��������Ѿƣ��ұ��������Կ���֡���\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/qaxe")->wield();
 
}

