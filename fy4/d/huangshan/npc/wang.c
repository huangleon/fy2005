// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("��Ө", ({ "wang ying", "wang"}) );
        set("gender", "Ů��" );
        set("age",22);
        set("long", "һ���彣�Ļ�ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 6, "����");
        set("combat_exp", random(10000)+1000);
        set("attitude", "friendly");
        
        set_skill("sword", 60+random(10));
	set_skill("siqi-sword",random(50)+30);
	set_skill("move",60);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40+random(40));
	map_skill("dodge","liuquan-steps");
        map_skill("sword", "siqi-sword");
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"��Ө����һָ������ú�ɽѽ�����ǻ�ɽ��ʤ����\n",
        }) );
        
        set("chat_chance_combat", 30);
	
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

