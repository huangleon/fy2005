// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("̫����", ({ "taibai yi", "taibai"}) );
        set("gender", "����" );
        set("age",32);
        set("long", "һ���嵶�Ļ�ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 5, "����");
        set("combat_exp", random(500000)+500000);
        set("attitude", "friendly");
        
        set_skill("blade", 100);
	set_skill("qiusheng-blade",100);
	set_skill("move",60);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("liuquan-steps",150);
	map_skill("dodge","liuquan-steps");
	map_skill("blade", "qiusheng-blade");
	map_skill("parry","qiesheng-blade");
	
        set("chat_chance", 5);
        set("chat_msg", ({
			name()+"˵����ʦ����ϲ��ɱ���ص��ˣ�����\n",
        }) );
        set("chat_chance_combat", 30);
	
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingsheng" :),
        }) );
        
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/blade")->wield();
}

