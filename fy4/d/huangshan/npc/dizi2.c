// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("СĽ��", ({ "mu rong","murong"}) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", "һ�����������Ļ�ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 5, "����");
        set("combat_exp", 5500000);
        set("attitude", "friendly");
		set("class","legend");
	    	
        set("chat_chance", 1);
        set("chat_msg", ({
		name()+"˵����ʦ����ϲ�����ˣ�����\n",
        }) );
        
 
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","diesword",1);
		setup();
		carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword",([	"name": "����",
						"long": "һ���û�ɽ���������ɵĳ�����\n",
					]))->wield();   
}

/*
void init()
{	
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting())
    	if (me->query("marks/��ɽѧ��") && me->query("class")=="legend") {
    	   	remove_call_out("greeting");
               	call_out("greeting", 1, me);
    	}   
}

int greeting(object me)
{
    message_vision(CYN"$N˵��ȥ���ҵ������Ƕ����������̽����Ҽ��У��㿴�ɲ��ɣ�\n"NOR,this_object());
    message_vision(CYN"$N˵�����������,ʦ��˵���ǿ��Ի���ѧѧ��\n"NOR,this_object());  
    return 1;
}

int recognize_apprentice(object ob)
{
    	if (ob->query("marks/��ɽѧ��") && ob->query("class")=="legend") {
    	  	return 1;
    	}   
	return 0;
}*/