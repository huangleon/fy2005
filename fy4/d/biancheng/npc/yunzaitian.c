#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();

void create()
{
    	set_name("������",({"yun zaitian","yun"}));
    	set("title","���зɺ�");
    	set("long","
һ�������ѩ��������ͱȻ�����СЩ����Ҳ����ʮ�����ң�ԲԲ������
���΢�룬��Цʱ�����˾��úܿ��ס�\n");
     	set("gender","����");
    	set("age",42);
    	set("reward_npc",1);
    	set("difficulty",5);
    	    	
    	set("combat_exp",6000000);  
    	set("attitude", "friendly");
    	    	
    	set("inquiry", ([
        	"������" : 	(: show_me :),
        	"������" : 	(: show_me :),
          	"���Ⱥ" :	 (: show_me :),
	 		"��"	 :	 (: show_me :),
   			"������" :	 (: show_me :),
   			"mache":	 (: show_me :),
   		]));
    	
    	set("death_msg",CYN"\n$N˵������һ���Ҳ����İ��� \n"NOR);  		
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			name()+"���������·������ϰ�֮�������λӢ�۽�ҹ��ȥС�á���\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",250,240,0,"/obj/weapon/","fighter_w","xuezhan-spear3",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": WHT"����"NOR,
    						"long": "һ����ѩ�İ��¡�\n",
    						 ]))->wear();    
    	carry_object("/obj/weapon/spear",([	"name": WHT"�����"NOR,
    						"long": "һ�����������ɵĳ��ˡ���\n",
    						"value": 0,
    						 ]))->wield();  
    
}


int show_me(){
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if (!REWARD_D->check_m_success(me,"����߳�")){
		message_vision(CYN"$N����$n����������Ŀ���ƺ�Ҫ��$n������\n",ob,me);
		command("say ������Ҫ��Ŀ��ˣ���������Ȼ���뵽��");
		command("say �����ò���Ŀ��ˣ�����Ҳ�Ƕ��ࡣ");
		return 1;
	}
	
	message_vision(CYN"$Nһ����˵���Ǳ���������������ã����ϰ���ӭ���������ݡ�\n"NOR,ob);
	return 1;
}

