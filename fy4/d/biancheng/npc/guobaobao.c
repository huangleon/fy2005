#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("������",({"guo baobao","guo","baobao"}));
   	set("long","һ��ʮ��ĺ��ӣ���������һ���󵶡�������ĵ������������˻�����\n");
     	set("gender","����");
    	set("age",10);
    	set("group","guo");
    	
    	 	
    	set("combat_exp",200000);  
    	set("attitude", "friendly");
    	    	
    	set("death_msg",CYN"\n$N�ҽ�һ��������ȥ��\n"NOR);  	
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		"������˵������Ҫɱ��үү��������ҲҪɱ�㣡�� \n"
    	}) );    	    	
    	 	
	auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
	set("class","none");
	setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  WHT"������"NOR,
    						"long": "һ���Ұ׵����¡�\n",
    						 ]))->wear();
    	carry_object("/obj/weapon/blade",([
    						"name": "��ͷ��",
    						"long": "һ���󵶣�����������������\n",
    						"value": 0,
    						  ]))->wield();    
    
}
