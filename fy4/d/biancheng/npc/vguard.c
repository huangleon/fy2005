#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("����׳��",({"whitecloth guard","guard"}));
	set("title","������");
   	set("long","
����׳���������õ������������Ⱥ�Ӹ�����ļ���ĺ��֡��׻�˵��
��ȭ�ѵ�˫�֣��ú��򲻹��˶࣬��������ã�Ӳ������̫���ˡ�\n");

     	set("gender","����");
    	set("age",42);
    	set("group","wanmatang");
    	 	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	   	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("busy_immune",random(2)+1);
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(100) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"�������������ر����ӣ������������������������\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","smallguy",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "�̴�װ",
    						"long": "һ���̴�װ��\n",
    						 ]))->wear();    
}
