// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>
int chant();

void create()
{
    	set_name("һǿ", ({ "master yi", "master"}) );
    	set("nickname", HIM "��ʦ"NOR);
    	set("vendetta_mark","shaolin");
    	create_family("������", 18, "����");
    	set("long","���ִ�ʦ������Ϊ���ֵ�һ�������ɣ����ٰ��࣬�㶼�����Ĺ��͡�\n");
    	set("gender", "����" );
    	set("age", 64);
    	
    	set("attitude","friendly");
        set("combat_exp", 9200000);
    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    	    
    	auto_npc_setup("wang",200,220,0,"/obj/weapon/","fighter_w","chant",2);
    	setup();   	
    	carry_object("obj/armor/cloth",([	"name": "��ʦ��",
    						"long": "һ����ʦ����\n",
    						 ]))->wear();   
}
