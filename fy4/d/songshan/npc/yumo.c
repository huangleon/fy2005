// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();

void create()
{
    set_name("����ħ", ({ "master yumo", "master"}) );
    set("nickname", HIW "��"NOR);
    set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 4);
    set("age", 64);
    set("per", 35);
    set("class","beggar");
    set("attitude","friendly");
    
    set("pursuer", 1);
    
    set("long", "�������µ�һ���İ�����ʦ�壬������������ȱ�ǰ�ϰ����δ����ؤ�\n");
    create_family("ؤ��", 6, "ʦ��");
    set("rank_nogen",1);
    set("ranks",({"�������","һ������","��������","��������","�Ĵ�����",
                      "�������","��������","�ߴ�����","�˴�����","�Ŵ�����",
                      "����","������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));

    set("combat_exp", 2000000);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_w","dagou-stick",1);
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/staff")->wield();
}

void attempt_apprentice(object me)
{
    	command("grin");
        command("say ���Һ�����һ·����\n");
}


int heal_up()
{
	if(environment() && !is_fighting() && !is_busy()
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}