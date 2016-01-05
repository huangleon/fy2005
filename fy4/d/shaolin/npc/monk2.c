// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("class","shaolin");
        set("age",random(20)+ 32);
	set("nickname","��ɮ");
        set("long", "����������ר�����ŵ���ɮ��\n");
	set("vendetta_mark","shaolin");
        create_family("������", 19, "����");
        set("combat_exp", 1000000);
        
        set("attitude", "friendly");
        set("agi", "10");
        
        set_skill("whip", 100);
	set_skill("tianlongwhip",100);
	set_skill("move",100);
	set_skill("puti-steps",100);
	set_skill("dodge",100);
	set_skill("force",100);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("dabei-strike",100);
	
	map_skill("parry","tianlongwhip");
	map_skill("unarmed","dabei-strike");
	map_skill("dodge","puti-steps");
	map_skill("whip", "tianlongwhip");
	
        set("chat_chance_combat", 1);
	set("chat_msg_combat", ({
//              (: perform_action, "whip.sijiaotianlong" :),
        	(: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        
        setup();
	carry_object(__DIR__"obj/monk22_cloth")->wear();
	carry_object(__DIR__"obj/whip")->wield();
}

