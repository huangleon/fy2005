#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("��ʮһ",({"ma shiyi","ma","shiyi"}));
	set("title","������ ����");
   	set("long","���Ⱥ������������û�����֣�ֻ�д��š�\n");
     	set("gender","����");
    	set("age",42);

    	set("group","wanma");
    	set("combat_exp",6500000);  
    	set("attitude", "friendly");

    	set("reward_npc",1);
    	set("difficulty",3);
    	    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: name()+"�е��������˰���ץ�̿�������\n",	
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        	
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "�����",
    						"long": "һ������ӡ�\n",
    						 ]))->wear();    
    
}
