#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("������",({"du qinglian","du"}));
	set("title",HIC"��������"NOR);
   	set("long","
����ɫ�԰ף��ݷ�������ݣ���ȴЦ���º͡���ֹ���ţ�����Ҳ����������
������Ȼ������Ȼ�в��������������������õ��£��������������͡�������
��ʲô�¶�������Ȥ�����������Ҳ����Ȥ��
\n");
     	
     	set("gender","����");
     	
    	set("age",32); 	 	
 	
	set("reward_npc",10);
    	
    	set("combat_exp",7500000);  
    	set("attitude", "heroism");
    	
    	set("death_msg",CYN"\n$N˵�������߲��������߲��ư�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
        
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"����������ѩ�������ʣ���÷�����㡣��¿���Ź��������춣����\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
	
	setup();
    	carry_object(__DIR__"obj/qiucloth")->wear();
    	carry_object(__DIR__"obj/dustick")->wield();    
    
}

