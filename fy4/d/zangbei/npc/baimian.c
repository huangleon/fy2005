#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("��������",({"baimian langzhong","baimian","langzhong"}));
		set("title",YEL"����կ �϶�"NOR);
   		set("long","
��������������կ�Ķ����ҡ������������ܰף�Ҳ��û�������У�����������
�ú���û��һ����������ţ��ǻ���ʲô���ֺú��������������ѽ��Լ�����
�������ˡ�\n");
     	
     	set("gender","����");
     	set("group","longhuzhai");
     	
    	set("age",32); 	 	
    	    	
    	set("reward_npc",2);
    	
    	set("longhu_boss", 1);
    	set("combat_exp",4500000);  
    	set("attitude", "friendly");
    	    	
    	set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"�������е���������������˱����Ͳ�ϲ����ܵġ���\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/gsword")->wield();    
    
}


void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
        	if(owner=me->query("possessed")) me = owner;
//        	if (REWARD_D->riddle_check(me,"�����θ���")==1)
        		me->set("marks/longhuzhai/��������",1);
        }
        ::die();
}
