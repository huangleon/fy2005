#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("��������",({"shaonian"}));
//    set("title","��׾޺�");
   	set("long","
һ��Ӣ�������꣬��������ϸ����ܿ�������������ɷ������ڣ�
��������\n");

     	set("gender","����");
    	set("age",22);
		set("group","murong");
    	 	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	
   	   	set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"�̲�ס��Ц�����ض������ã��ߣ��ô�����ɡ���\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","sharen-sword",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": MAG"������"NOR,
    						"long": "һ����������\n",
    						 ]))->wear();    
    
}
