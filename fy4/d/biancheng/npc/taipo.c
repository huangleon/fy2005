#include <ansi.h>
inherit NPC;


void create()
{
    	set_name("�׷��ԲԵ���̫��",({"taipo"}));
   		set("long","�׷��ԲԵ���̫�������������ӣ����ǵ��߳�����\n");
     	set("gender","Ů��");
    	set("age",72);
    	set("per",10); 	
    	set("int",22);
    	set("cor",30);
    	set("cps",20);
    	
    	set("combat_exp",500000);  
    	set("attitude", "friendly");
    	
 		set("chat_chance",1);
    	set("chat_msg",({
		"�׷��ԲԵ���̫��˵�����������Ѿ����������ˡ���������\n",
    	}) );    	    	
    	    	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": "�ֲ���",
    						"long": "һ���ֲ��¡�\n",
    						 ]))->wear();    
    
}
