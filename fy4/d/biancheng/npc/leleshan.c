#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("����ɽ",({"leleshan"}));
	set("title","��������");
   	set("long","
�����ϴ��ż���ŵ����ƣ��ǵ�ϴ�úܸɾ���������һֻ������û�С�������
��ֻ�����ֺڵ���ţ�����˫�������õĲ�Ь����ֻ��Ь���׶�������һ�롣
��ɫ���޵����þƶ��������öĶ���ʤ����ν���ޣ����������Գ�����������\n");
     	set("gender","����");
    	set("age",42);
    	 	
    	set("combat_exp",7000000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",5);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"��������ɫ������ϴ������Ԫ������������ϴ���õġ���\n"
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","taiji",2);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "�������װ",
    						"long": "һ����ŵ����ƣ��ǵ�ϴ�úܸɾ���������һֻ������û�С�\n",
    						 ]))->wear();        
    
}
