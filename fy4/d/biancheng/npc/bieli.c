#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("������",({"xiao bieli","xiao","bieli"}));
    	set("title","��װ�ܻ��������κ������������");
    	set("long","
�����ް߰ף�����ÿһ�������У�����֪�����Ŷ��ٻ��֣�����ʹ�࣬����
���ܣ���һ˫��ȴ����ϸ����Ů�������źܻ����������������ѽӽ��ݳޡ�\n");

     	set("gender","����");
    	set("age",52);
    	 	
   		set("combat_exp",7000000);  
    	set("attitude", "friendly");
    	    	
    	set("reward_npc",1);
    	set("difficulty",5);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"���������ڽ�����һ���������ذ������ϣ��ڳ��˸����ԡ�\n"
    	}) );    	    	
    	
		auto_npc_setup("wang",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
		set_skill("tanzhi-shentong",160);
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "�����Ž��",
    						"long": "һ�������Ž�ӡ�\n",
    						 ]))->wear();     
    
}
