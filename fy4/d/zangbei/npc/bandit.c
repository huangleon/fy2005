#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("ɽկ���",({"bandit"}));
	set("title",YEL"����կ"NOR);

   	set("long","һ�������£��������λθֵ���С���ˡ�\n");
     	set("gender","����");
    	set("age",32);
    	set("group","longhuzhai"); 	
 
    	set("combat_exp",2000000);  
    	set("attitude", "aggressive");
    	    	
    	set("death_msg",CYN"\n$N�е�������֪�������Ͳ��������ˡ�����\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: "ɽկ��޽е����������ŵķ��򣬵����ǲ�����ѽ����\n",
		15: "ɽկ��޽е������������������������ס�ˡ���\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        
        set("inquiry", ([
        	"����" : 	"����ô���������ˣ�\n",
             	"����" : 	"������կ����ЪϢ�أ�\n",      
             	"կ��" : 	"���������򲻵��ң�����\n",
             	"����կ" : 	"���������򲻵��ң�����\n",
             	"���" : 	"���������򲻵��ң�����\n",
   	]));
   	
    	set("chat_chance",1);
    	set("chat_msg",({
		"ɽկ��޽е���������կ�Ĵ����ڴˣ������˵������ˣ���\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",150,130,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "�ڲ��̿�",
    						"long": "һ���ڲ��̿���\n",
    						 ]))->wear();    
    
}


int accept_object(object who, object ob)
{

	if( ob->value() >= 10000) {
                        command( "say ������������Т˳�ķ��ϣ��͸��������ɡ�");
                        who->set_temp("wild4_pass", 1);
                        who->remove_all_killer();
                        return 1;
                } else {
                    	command("say �ޣ��㵱��ү�ǽл��ӣ�\n");
                        return 0;
                }
        return 0;
} 
