#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("�����",({"gongsun duan","gongsun"}));
    	set("title","��׾޺�");
    	set("long","
����������ף�һ����£�����ϵ��һ�߿��ţƤ����Ƥ����б����
�������ڱ��������䵶�����ﻹ���ű��ơ��Ʊ����������������
̫�󣬵����������ֻ��Ҳδ��������ס��\n");

     	set("gender","����");
    	set("age",42);
    	 	
    	set("combat_exp",7500000);  
    	set("attitude", "heroism");
    	
    	set("reward_npc",1);
    	set("difficulty",5);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        set("smartnpc_busy",1);
        
    	set("chat_chance",1);
    	set("chat_msg",({
		"��׾޺����ͷ���������ҽй���ϣ����Ǹ����ˣ��������\n"
    	}) );    	    	
    	    	
		auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","bat-blade",2);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/weapon/blade/blade_gongsun")->wield();
}
