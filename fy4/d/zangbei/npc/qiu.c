#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("����",({"qiu fengcheng","qiu"}));
	set("title",HIW"��ǹ����"NOR);
   	set("long","
�����ᡢ�������ߴ�Ӣ����������һ�ֽ������õ����ʡ������ϴ�����
һϮ��ֵǧ������ã����������Թ⻪��Ŀ����ǹ�������濴�����죬��
�յĳ����۾��������˵�����ı�ʹ�����ǡ�
\n");
     	
     	set("gender","����");
     	
    	set("age",32); 	 	
    	set("per",40);
	
		set("reward_npc",10);
    	
    	set("combat_exp",7500000);  
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
		name()+"��������ճյĳ��񣬺������û�������������\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",300,250,0,"/obj/weapon/","fighter_w","xuezhan-spear2",2);
	
		setup();
    	carry_object(__DIR__"obj/qiucloth")->wear();
    	carry_object(__DIR__"obj/qiuspear")->wield();    
    
}

