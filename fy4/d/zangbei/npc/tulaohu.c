#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("���ϻ�",({"tu laohu","tu","laohu"}));
	set("title",YEL"����կ ����"NOR);
   	set("long","
���ϻ���ͷ�Ա����ͱ�һֻ�ϻ��������˶��٣������ںȾ�֮������ֱ����
��������Ҳ���ϻ���Ҫ�ס������׵���ȭͷ����˵��һȭ���Դ���ֻ���ϻ���
����Ȼû����Ŀ�����ȴû���˸һ��ɡ���Ϊ��һȭ���������Ѳ��١�\n");
     	set("gender","����");
    	set("age",32);
    	set("group","longhuzhai");
    	 	
		set("reward_npc",2);
	
    	set("combat_exp",4500000);  
    	set("attitude", "friendly");
    	set("longhu_boss", 1);
    		
    	set("death_msg",CYN"\n$N��һ�ٶ���ص����ӣ�����÷��˳�ȥ���ɳ�ȥ�����⣬���ص�ײ
��ǽ�ϣ�������ǽ��������\n"NOR);  	

    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(50) :),
        }) );

    	set("chat_chance",1);
    	set("chat_msg",({
		"���ϻ���Ц����������������Ҹ��ط�˯�������Ҵ�ط��ˣ�����û�д���ֻ�йײġ���\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike-jg",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();
   
}



void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
	        if(owner=me->query("possessed")) me = owner;
//        	if (REWARD_D->riddle_check(me,"�����θ���")==1)
        		me->set("marks/longhuzhai/���ϻ�",1);
        }
        ::die();
}