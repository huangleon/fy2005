#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

string look_lu();

void create()
{
    	set_name("��������",({"anonymous oldman","oldman"}));
		set("long",(: look_lu() :));
   		set("gender","����");
     	
    	set("age",72); 	 	
    	
    	set("combat_exp",8500000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","longfenghuan",1);
	
		setup();
    	carry_object(__DIR__"obj/cyancloth")->wear();
    	carry_object("/obj/weapon/hammer/tiedan")->wield(); 
 
}



string look_lu(){
	this_player()->set_temp("marks/kuaihuo/�����_½����",1);
	return "���˵���ĸߴ󣬺ܿ�ΰ���ż�����ɫ�ĳ��ۣ����׵�ͷ�����˷��٣���
�ﶣ�����죬����������ö������\n";
}