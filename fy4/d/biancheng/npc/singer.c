#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("������ͷ",({"old singer","singer","oldman"}));
        set("title","˵���");
        set("long","
������ͷ�����Ѿ���ʮ�����ˣ��ڱ߳���˵������Ϊ����������Ȼ��������������
�˺ܶ�п�ĺۼ���������ȴû�е�ͷ�����ı������䣬�ж�����̫��������
����ƾ���Լ���Ŭ��ȥ׬ȡ����ķ��á�\n");
    	set("gender","����");
    	set("age",72);
    	 	
    	set("combat_exp",2000000);  
    	set("attitude", "friendly");
    	
    	set("death_msg",CYN"\n$N�����ﹾ���������ƺ���˵ʲô��ȴ����û˵������ \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n������ͷ�е���������Ϲ�ͷ����ƴ�ˣ�����\n",
        ]) );    	

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );
        
    	set("chat_chance",1);
    	set("chat_msg",({
		"������ͷ�������֨֨ѽѽ���˼�������:����ʻʣ��ػʻʡ�����Ѫ�����޹⡣
һ�������ã������У��˶ϳ�����\n",
		"������ͷ���ų���������ʻʣ��ػʻʡ�����Ѫ���˶ϳ���һ�������ã�
����ع��硣��\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",150,160,0,"/obj/weapon/","fighter_w","fumostaff",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/music/erhu")->wield();  
    
}
