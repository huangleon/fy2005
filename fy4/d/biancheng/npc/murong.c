#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("Ľ������",({"murong mingzhu","murong","mingzhu" }));
    	set("long","
һ��Ӣ�������꣬������������ɷ������ڣ��������������ų�����
�����ϵı�ʯ�������⣬���ϻ������Ͻ�����������������۰���һ
��ҹ���顣\n");

     	set("gender","����");
    	set("age",22);
    	 	
    	set("combat_exp",6000000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",3);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"Ľ�����鲻м�ؿ�����һ��˵�������ȺҲ�����ˣ���\n"
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": MAG"������"NOR,
					"long": "һ����������\n",
					 ]))->wear();  
    	carry_object("/obj/weapon/sword",([	"name": WHT"���������"NOR,
						"long": "һ����ⱦ���ĳ���������������װ�εġ�\n",
						"value": 0,
					 ]))->wield();  
}
