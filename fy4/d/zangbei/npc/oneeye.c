#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("������",({"one eye","eye"}));
	set("title",YEL"����կ �ϴ�"NOR);
   	set("long","
������������կ���ϴ���ϲ����һ��ڲ�������ֻϹ�˵��۾�����Ϊ��
���������ӿ������������ϡ���ʵ�ϣ���Ҳ��ȷ�Ǹ��������ϵ��ˣ���Ϊ
����Ȼ���̣�ȴ�ܹ�ƽ��ֻ�й�ƽ���ˣ������������ֺú����ϴ�\n");
     	
     	set("gender","����");
    	set("group","longhuzhai");
    	set("age",42);
    	 		    	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	
    	set("longhu_boss", 1);
    	set("reward_npc",3);
    	    	
    	set("death_msg",CYN"\n$N�ں޵�˵�����������һֻ�ۻ��ڵĻ������ľ������ˡ���\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"������Ц�ŵ�������֪���Ѹ��մ������������ﶺ����ã���\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,250,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/gblade")->wield();    
    
}


void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
        	if(owner=me->query("possessed")) me = owner;
//        	if (REWARD_D->riddle_check(me,"�����θ���")==1)
        		me->set("marks/longhuzhai/������",1);
        }
        ::die();
}