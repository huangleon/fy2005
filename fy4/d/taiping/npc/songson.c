#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("������",({"song saiyu","saiyu","song"}));
    	set("title","ò���˰�");
    	set("long","
������������ĸɶ��ӣ����ϴ��ż�ˮ��ɫ�����ӣ����ﻹ��ҡ�ű����ȡ�
�����˷ǵ����ò��ѿ���װ�����Ҳ�ܿ�����ȴƫƫ�е������ᡣ\n");
    	set("gender","����");
    	set("age",22);
    	set("no_arrest",1);
    	
    	set("combat_exp",1500000);
		set("attitude","friendly");
	
		
		set("per",40);
	    	
    	set("inquiry", ([
        	"*" : 	"Ѫū�����ڵ��ң�û��������ġ�\n",
        ]));
    	set("death_msg",CYN"\n$N˵���죬�μҾ����ˡ������� \n"NOR);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"�����������ŵ�����Ѫū������Ҫ��С�������������ҵģ����ĵ��ʮ�����\n",	
    		"������˵������ĸ�ڴˣ������¿�ͷ��kneel������\n"NOR,
    	}) );
    	
    	auto_npc_setup("wang",150,120,0,"/obj/weapon/","fighter_w","xinyue-dagger",1);
		set_skill("iron-cloth",100);
		set_skill("xinyue-dagger",80);			
		setup();   
    	carry_object(__DIR__"obj/greencloth")->wear();
    	carry_object(__DIR__"obj/zheshan")->wield();
}


