#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;


void create()
{
    set_name("��ľ��",({"carpenter li","carpenter","li"}));
    set("title","С³��");
    set("long","
��ľ������������̫ƽ�����ǳ������ģ���������ļҾߣ�����ɥ��Ĺײģ�
������һ�Ұ��졣\n");
    	set("gender","����");
    	set("age",32);
    	 	
    	set("combat_exp",2200000);  
    	set("attitude", "friendly");
    	
    	set("death_msg",CYN"\n$N������ˮ�ؿ���һ��������ļҾߡ������� \n"NOR);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n��ľ���е������ӽ����������һ���ײģ�����\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"��ľ���ֳ��ٸ������²�������������æµ�š�\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","wuche-axe",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/paxe")->wield();  
    
}
